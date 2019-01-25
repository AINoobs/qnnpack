/*
 * Copyright (c) The QNNPACK contributors.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>
#include <qnnpack.h>
#include <benchmark/benchmark.h>

class ThreadPoolEnv {
 public:
  ThreadPoolEnv() : pool_size_(1), pool_(nullptr) {
    char* pool_size_str = getenv("QNNPACK_THREADPOOL_SIZE");
    if (pool_size_str != nullptr) {
      pool_size_ = atoi(pool_size_str);
      if (pool_size_ > 0) {
        pool_ = pthreadpool_create(pool_size_);
        if (pool_ != nullptr) {
          std::cout << "Using thread pool with " << pool_size_ << " threads" << std::endl;
        }
      }
    }
  }

  pthreadpool_t pool() const { return pool_; }

  ~ThreadPoolEnv() {
    if (pool_ != nullptr) {
      pthreadpool_destroy(pool_);
    }
  }

 private:
  int pool_size_;
  pthreadpool_t pool_;
};
