/**
 * @author Ayoub Chouak (a.chouak@protonmail.com)
 * @file   DummyObject.h
 * @brief  Dummy plugin object example
 */

#ifndef YAMPL_DUMMY_OBJECT_H
#define YAMPL_DUMMY_OBJECT_H

#include "yampl/plugin/IObject.h"

#include <cstdint>
#include <iostream>

namespace yampl
{
    namespace example
    {
        /**
         * @brief Minimal example of an exportable object
         * @note  A plugin object must derived from IObject or one of its descendants
         */
        class DummyObject : public yampl::plugin::IObject
        {
            public:
                static const uint32_t __OBJECT_VERSION {0};

                DummyObject() {
                    std::cout << "[PLUGIN][+] DummyObject::DummyObject()" << std::endl;
                }

                ~DummyObject() override {
                    std::cout << "[PLUGIN][+] DummyObject::~DummyObject()" << std::endl;
                }
        };
    }
}

#endif // YAMPL_DUMMY_OBJECT_H
