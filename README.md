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
---------------------
A YAMPL plugin must adhere to a strict API defined in `PluginApi.h`. This file contains all the structures and macros needed to build a compatible plugin.
A plugin is essentially composed by three procedures:
- *PluginMain*: The entry point of the plugin. This is called by the application as soon as the plugin dynamic module is loaded in memory. This procedure initializes the plugin internal structures, negotiates the API version and registers all the objects it exposes to the application.
- *CreateObject*: The hook procedure called by the application whenever it needs to create an object of some type.
- *DestroyObject*: The hook procedure called by the application to destroy an object previously created by the plugin.

A plugin must declare three essential parameters:
- *Moniker*: a moniker is a unique identifier assigned to the plugin. It's very important that this identifier is unique, hence it's highly recommended to fully qualify the moniker; a good moniker for your plugin could resemble **com.mywebsite.yampl-my-plugin**.
- Plugin *Major version*
- Plugin *Minor version*

In order to export the plugin, the **YAMPL_PLUGIN** helper macro must be used. The macro takes three parameters, namely the *Moniker*, the plugin *Major version* and *Minor version*. This macro exports a public header that contains the essential information needed by the application to bootstrap the plugin and communicate with it via the strict minimal API defined in `PluginApi.h`.
