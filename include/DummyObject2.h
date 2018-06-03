/**
 * @author Ayoub Chouak (a.chouak@protonmail.com)
 * @file   DummyObject2.h
 * @brief  Dummy plugin object versioning example
 */

#ifndef YAMPL_DUMMY_OBJECT2_H
#define YAMPL_DUMMY_OBJECT2_H

#include "DummyObject.h"

namespace yampl
{
    namespace example
    {
        /**
         * @brief Example of how the same object can come in different versions
         * 
         */
        class DummyObject2 : public DummyObject
        {
            public:
                static const uint32_t __OBJECT_VERSION {1};

                void new_feature() const {
                    std::cout << "This is a new feature of DummyObject" << std::endl;
                }

                DummyObject2() {
                    std::cout << "DummyObject2::DummyObject2()" << std::endl;
                }

                ~DummyObject2() override {
                    std::cout << "DummyObject2::~DummyObject2()" << std::endl;
                }
        };
    }
}

#endif // YAMPL_DUMMY_OBJECT2_H
