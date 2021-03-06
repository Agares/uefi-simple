UEFI:SIMPLE - EFI development made easy
=======================================

A simple UEFI "Hello World!" style application that can:
* be compiled on either on Windows or Linux (using Visual Studio 2013 or MinGW-w64).
* be compiled for either x86_32 or x86_64 UEFI targets
* be tested on the fly, through a [QEMU](http://www.qemu.org)+[OVMF](http://tianocore.github.io/ovmf/)
  UEFI virtual machine.

## Prerequisites

* [Visual Studio 2013](http://www.visualstudio.com/products/visual-studio-community-vs)
  or [MinGW-w64](http://mingw-w64.sourceforge.net/) (with msys, if using MinGW-w64 on Windows)
* [QEMU](http://www.qemu.org)
* git
* wget, unzip, if not using Visual Studio

## Sub-Module initialization

For convenience, the project relies on the gnu-efi library (but __not__ on
the gnu-efi compiler itself), so you need to initialize the git submodules:
```
git submodule init
git submodule update
```

## Compilation and testing

If using Visual Studio, just press `F5` to have the application compiled and
launched in the QEMU emulator.

If using MinGW-w64, issue the following from a command prompt:

`make qemu`

Note that in both cases, the debug process will download the current version of
the EDK2 UEFI firmware and run your application against it in the QEMU virtual
UEFI environment.  
In case the download fails, you can download the latest from:
http://tianocore.sourceforge.net/wiki/OVMF and extract the `OVMF.fd` as
`OVMF_x86_32.fd` or `OVMF_x86_64.fd`in the top directory.
