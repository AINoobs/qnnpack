/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <gtest/gtest.h>

#include "average-pooling-operator-tester.h"

#include <qnnpack/params.h>


TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_1xM_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_1xM_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 3; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (size_t paddingLeft = 0; paddingLeft <= 1; paddingLeft++) {
        for (size_t paddingRight = 0; paddingRight <= 1; paddingRight++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(2)
            .inputWidth(poolSize + 2)
            .paddingLeft(paddingLeft)
            .paddingRight(paddingRight)
            .poolingHeight(1)
            .poolingWidth(poolSize)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_1xM_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 4)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .strideWidth(2)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_Mx1_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_Mx1_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_Mx1_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_input_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (float inputScale = 0.01f; inputScale < 100.0f; inputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_input_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (int32_t inputZeroPoint = 0; inputZeroPoint <= 255; inputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_output_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (float outputScale = 0.01f; outputScale < 100.0f; outputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_output_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (int32_t outputZeroPoint = 0; outputZeroPoint <= 255; outputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_output_min) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMin(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMin(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_small_pool_with_output_max) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMax(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMax(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_1xM_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_1xM_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = 3; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (size_t paddingLeft = 0; paddingLeft <= 1; paddingLeft++) {
        for (size_t paddingRight = 0; paddingRight <= 1; paddingRight++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(2)
            .inputWidth(poolSize + 2)
            .paddingLeft(paddingLeft)
            .paddingRight(paddingRight)
            .poolingHeight(1)
            .poolingWidth(poolSize)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_1xM_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 4)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .strideWidth(2)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_Mx1_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_Mx1_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_Mx1_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_input_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (float inputScale = 0.01f; inputScale < 100.0f; inputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_input_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (int32_t inputZeroPoint = 0; inputZeroPoint <= 255; inputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_output_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (float outputScale = 0.01f; outputScale < 100.0f; outputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_output_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      for (int32_t outputZeroPoint = 0; outputZeroPoint <= 255; outputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_output_min) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMin(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMin(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_many_channels_large_pool_with_output_max) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels += 3) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMax(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMax(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_1xM_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_1xM_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 3; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      for (size_t paddingLeft = 0; paddingLeft <= 1; paddingLeft++) {
        for (size_t paddingRight = 0; paddingRight <= 1; paddingRight++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(2)
            .inputWidth(poolSize + 2)
            .paddingLeft(paddingLeft)
            .paddingRight(paddingRight)
            .poolingHeight(1)
            .poolingWidth(poolSize)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_1xM_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 4)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .strideWidth(2)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_Mx1_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_Mx1_pool_with_padding) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_Mx1_pool_with_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (size_t paddingTop = 0; paddingTop <= 1; paddingTop++) {
        for (size_t paddingBottom = 0; paddingBottom <= 1; paddingBottom++) {
          AveragePoolingOperatorTester()
            .batchSize(1)
            .inputHeight(poolSize + 1)
            .inputWidth(3)
            .paddingTop(paddingTop)
            .paddingBottom(paddingBottom)
            .poolingHeight(poolSize)
            .poolingWidth(1)
            .channels(channels)
            .testQ8();
        }
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_input_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (float inputScale = 0.01f; inputScale < 100.0f; inputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputScale(inputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_input_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (int32_t inputZeroPoint = 0; inputZeroPoint <= 255; inputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .inputZeroPoint(uint8_t(inputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_output_scale) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (float outputScale = 0.01f; outputScale < 100.0f; outputScale *= 3.14159265f) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputScale(outputScale)
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_output_zero_point) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      for (int32_t outputZeroPoint = 0; outputZeroPoint <= 255; outputZeroPoint += 51) {
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(poolSize + 1)
          .inputWidth(3)
          .poolingHeight(poolSize)
          .poolingWidth(1)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
        AveragePoolingOperatorTester()
          .batchSize(1)
          .inputHeight(2)
          .inputWidth(poolSize + 1)
          .poolingHeight(1)
          .poolingWidth(poolSize)
          .channels(channels)
          .outputZeroPoint(uint8_t(outputZeroPoint))
          .testQ8();
      }
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_output_min) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMin(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMin(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, unit_batch_few_channels_with_output_max) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputMax(128)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(1)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputMax(128)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_small_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_small_pool_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_small_pool_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= qnnp_params.q8avgpool.mr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_large_pool) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_large_pool_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_many_channels_large_pool_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = qnnp_params.q8avgpool.kr; channels <= 3 * qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = qnnp_params.q8avgpool.mr + 1; poolSize <= qnnp_params.q8avgpool.mr + qnnp_params.q8avgpool.qr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_few_channels) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 2)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_few_channels_with_input_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .inputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}

TEST(AVERAGE_POOLING_OP, small_batch_few_channels_with_output_stride) {
  ASSERT_EQ(qnnp_status_success, qnnp_initialize());
  for (size_t channels = 1; channels < qnnp_params.q8avgpool.kr; channels++) {
    for (size_t poolSize = 2; poolSize <= 2 * qnnp_params.q8avgpool.kr; poolSize++) {
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(poolSize + 1)
        .inputWidth(3)
        .poolingHeight(poolSize)
        .poolingWidth(1)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
      AveragePoolingOperatorTester()
        .batchSize(3)
        .inputHeight(2)
        .inputWidth(poolSize + 1)
        .poolingHeight(1)
        .poolingWidth(poolSize)
        .channels(channels)
        .outputPixelStride(5 * qnnp_params.q8avgpool.kr)
        .testQ8();
    }
  }
}
