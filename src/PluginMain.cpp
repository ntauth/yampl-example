/**
 * @author Ayoub Chouak (a.chouak@protonmail.com)
 * @file   PluginMain.cpp
 * @brief  YAMPL Plugin example
 */

#include "PluginMain.h"

#include <cstdint>
#include <iostream>

static plugin_init_frame _gbl_init_frame;

hook_exec_status PluginMain(pplugin_init_frame frame)
{
    hook_exec_status status;

    // Sanity check
    if (frame == nullptr) {
        status = HOOK_STATUS_FAILURE;
    }
    // Plugin API version check
    else if (frame->api_version != PLUGIN_API_VERSION) {
        status = HOOK_STATUS_FAILURE;
    }
    else
    {
        // Store the frame
        _gbl_init_frame = *frame;

        // Register DummyObject
        object_register_params reg_params;
        reg_params.obj_type   = OBJ_PROTO_UNKNOWN;
        reg_params.hk_create  = yampl::example::HOOK_CreateObject;
        reg_params.hk_destroy = yampl::example::HOOK_DestroyObject;
            
	    hook_exec_status reg_status = frame->hk_register(&reg_params);

        if (reg_status == HOOK_STATUS_SUCCESS)
            status = HOOK_STATUS_SUCCESS;
        else
            status = HOOK_STATUS_FAILURE;
    }

    return status;
}

opaque_ptr yampl::example::HOOK_CreateObject(object_init_params* params)
{
    opaque_ptr obj;

    switch (params->type)
    {
        case OBJ_PROTO_UNKNOWN:
        {
            switch (params->obj_version)
            {
                case 0:
                case OBJECT_VERSION_ANY:
                    obj = reinterpret_cast<opaque_ptr>(new DummyObject);
                    break;
                case 1:
                    obj = reinterpret_cast<opaque_ptr>(new DummyObject2);
                    break;
                default:
                    obj = nullptr;
                    break;
            }

            break;
        }
        default:
            obj = nullptr;
            break;
    }

    return obj;
}

hook_exec_status yampl::example::HOOK_DestroyObject(opaque_ptr obj)
{
    hook_exec_status status;

    if (obj == nullptr) {
        status = HOOK_STATUS_FAILURE;
    }
    else
    {
        delete obj;
        status = HOOK_STATUS_SUCCESS;
    }

    return status;
}