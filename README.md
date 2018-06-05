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
A YAMPL plugin is essentially composed by three procedures:
- *PluginMain*: The entry point of the plugin. This is called by the application as soon as the plugin dynamic module is loaded in memory. This procedure initializes the plugin internal structures, negotiates the API version and registers all the objects it exposes to the application.
- *CreateObject*: The hook procedure called by the application whenever it needs to create an object of some type.
- *DestroyObject*: The hook procedure called by the application to destroy an object previously created by the plugin.
