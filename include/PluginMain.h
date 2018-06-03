/**
 * @author Ayoub Chouak (a.chouak@protonmail.com)
 * @file   PluginMain.h
 * @brief  YAMPL Plugin example
 */

#ifndef YAMPL_PLUGIN_MAIN_H
#define YAMPL_PLUGIN_MAIN_H

#include "yampl/plugin/PluginApi.h"

#include "DummyObject.h"
#include "DummyObject2.h"

/**
 * Plugin Information
 */
#define PLUGIN_MONIKER   "yampl-example"
#define PLUGIN_VER_MAJOR (uint8_t) 1
#define PLUGIN_VER_MINOR (uint8_t) 0

/**
 * @brief Routine invoked by the consumer to initialize the plugin
 * @note  PluginMain must adhere to this strict signature
 */
hook_exec_status PluginMain(pplugin_init_frame frame);

/* Export the plugin with the specified information */
YAMPL_PLUGIN(PLUGIN_MONIKER, PLUGIN_VER_MAJOR, PLUGIN_VER_MINOR)

namespace yampl
{
    namespace example
    {
        /**
         * @brief The hook functions are tasked with creating objects
         *        and destroying them when requested 
         */
        opaque_ptr HOOK_CreateObject(object_init_params*);
        hook_exec_status HOOK_DestroyObject(opaque_ptr);
    }
}

#endif // YAMPL_PLUGIN_MAIN_H