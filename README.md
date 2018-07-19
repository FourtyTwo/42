# 42
![alt text](https://github.com/FourtyTwo/42/blob/master/scripts/logo.png "Logo Title Text 1")
Its the answer

## What is 42?

42 is 42. Thats all you need to know.
More info is in the [FAQ](https://coin42.co/faq.html) of our site.
General info about 42 and other various topics is on our Github wiki.

## Compile instructions

## Ubuntu

First, you need to download the dependencies of 42, pretty simple because Ubuntu has that neat package manager.
Heres the gist of what you need:

` sudo apt-get install -y build-essential python-dev gcc g++ git cmake libboost-all-dev librocksdb-dev libreadline-dev `


If you cant install librocksdb-dev on your version of Ubuntu, no sweat man, just add the repo via PPA:


```
sudo add-apt-repository ppa:ethcore/ethcore -y
sudo apt-get update
sudo apt-get install librocksdb-dev
```

Alright, now thats out of the way, its time to compile 42!


```
git clone https://github.com/FourtyTwo/42.git
```
Then
```
cd 42
mkdir build
cd build
cmake ..
```
Then 
```
make -j4
```
Boom! You made it :D
Also if your having permision issues related to build_detect_platform and version.sh in external/rocksdb/build_tools, its a permissions thing. Do chmod +x to version.sh and build_detect_platform (or the whole damn folder if you like)

## Windows

Suprisingly enough, compiling 42 on Windows is actually not that hard! Its pretty simple, first just download the deps

You need [Visual Studio Community 2017](https://www.visualstudio.com/thank-you-downloading-visual-studio/?sku=Community&rel=15&page=inlineinstall)
When downloading, make sure you install Desktop Development with C++ and the VC++ 140 Toolchain (should be on the right of the installer screen) in order to compile correctly.
You also need [Cmake](https://cmake.org/download/) in order to make the MSVC solution file.
And last but not least, you need the dreaded [Boost 1.59.0](https://sourceforge.net/projects/boost/files/boost-binaries/1.59.0/) Make sure to download the MSVC 14 installer version of boost!

Alright, now thats out of the way let's build the answe- I mean 42!

In the x64 Native Tools Command prompt for Visual Studio 2017, go into the 42 folder
` cd <your-42-folder-file-path `
Now, we need to make the MSVC solution file
` cmake -G "Visual Studio 14 Win64" -DBOOST_ROOT=C:/local/boost_1_59_0 CMakeLists.txt `
Once its down making the build files, simply run this command in the same directory:
` MSBuild 42.sln /p:Configuration=Release /m `
Let it do its thing, and once it's done compiling go to /src/ and in the release folder the binaries will be there!

## Mac OSX

I dont have a Mac so I can't do this...sorry :(
