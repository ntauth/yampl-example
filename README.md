YAMPL Plugin Example
====================

This repository contains a minimal example of a plugin for the [YAMPL](https://github.com/ntauth/yampl) library.

Build, Test & Install
---------------------
``` bash
git clone https://github.com/ntauth/yampl
cd yampl
# Clone this repository into yampl/plugins
cd plugins
git clone https://github.com/ntauth/yampl-example
# Configure yampl
mkdir /path/to/build/directory
cd /path/to/build/directory
cmake /path/to/repo/root -DWITH_PLUGIN_EXAMPLE={ON(Default)|OFF}
# Build and install
make
make install
```

How to make your own?
-------
