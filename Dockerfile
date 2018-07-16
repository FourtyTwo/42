# daemon runs in the background
# run something like tail /var/log/turtlecoind/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/turtlecoind:/var/lib/turtlecoind -v $(pwd)/wallet:/home/turtlecoin --rm -ti turtlecoin:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG TURTLECOIN_BRANCH=master
ENV TURTLECOIN_BRANCH=${TURTLECOIN_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev \
      librocksdb-dev && \
    git clone https://github.com/FourtyTwo/42.git /src/42 && \
    cd /src/42 && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/42d /usr/local/bin/42d && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/42-wallet /usr/local/bin/42-wallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/42d && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/42-wallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/42 && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev librocksdb-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the 42d service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/42d 42d && \
    useradd -s /bin/bash -m -d /home/42 42 && \
    mkdir -p /etc/services.d/42d/log && \
    mkdir -p /var/log/42d && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/42d/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/42d/run && \
    echo "cd /var/lib/42d" >> /etc/services.d/42d/run && \
    echo "export HOME /var/lib/42d" >> /etc/services.d/42d/run && \
    echo "s6-setuidgid 42d /usr/local/bin/42d" >> /etc/services.d/42d/run && \
    chmod +x /etc/services.d/42d/run && \
    chown nobody:nogroup /var/log/42d && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/42d/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/42d/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/42d" >> /etc/services.d/42d/log/run && \
    chmod +x /etc/services.d/42d/log/run && \
    echo "/var/lib/42d true turtlecoind 0644 0755" > /etc/fix-attrs.d/42d-home && \
    echo "/home/42 true 42 0644 0755" > /etc/fix-attrs.d/42-home && \
    echo "/var/log/42d true nobody 0644 0755" > /etc/fix-attrs.d/42d-logs

VOLUME ["/var/lib/42d", "/home/42","/var/log/42d"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/42 export HOME /home/42 s6-setuidgid 42 /bin/bash"]
