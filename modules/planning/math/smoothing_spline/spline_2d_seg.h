/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file spline_2d_seg.h
 **/

#ifndef MODULES_PLANNING_SMOOTHER_SPLINE_SPLINE_2D_SEG_H_
#define MODULES_PLANNING_SMOOTHER_SPLINE_SPLINE_2D_SEG_H_

#include <utility>
#include <vector>

#include "modules/planning/math/polynomial_xd.h"

namespace apollo {
namespace planning {

class Spline2dSeg {
 public:
  // order represent the number of parameters (not the highest order);
  explicit Spline2dSeg(const std::uint32_t order);
  explicit Spline2dSeg(const std::vector<double>& x_param,
                       const std::vector<double>& y_param);
  ~Spline2dSeg() = default;

  bool SetParams(const std::vector<double>& x_param,
                  const std::vector<double>& y_param);

  std::pair<double, double> operator()(const double t) const;
  double x(const double t) const;
  double y(const double t) const;
  double derivative_x(const double t) const;
  double derivative_y(const double t) const;
  double second_derivative_x(const double t) const;
  double second_derivative_y(const double t) const;
  double third_derivative_x(const double t) const;
  double third_derivative_y(const double t) const;

  const PolynomialXd& spline_func_x() const;
  const PolynomialXd& spline_func_y() const;
  const PolynomialXd& derivative_x() const;
  const PolynomialXd& derivative_y() const;
  const PolynomialXd& second_derivative_x() const;
  const PolynomialXd& second_derivative_y() const;
  const PolynomialXd& third_derivative_x() const;
  const PolynomialXd& third_derivative_y() const;

 private:
  PolynomialXd spline_func_x_;
  PolynomialXd spline_func_y_;
  PolynomialXd derivative_x_;
  PolynomialXd derivative_y_;
  PolynomialXd second_derivative_x_;
  PolynomialXd second_derivative_y_;
  PolynomialXd third_derivative_x_;
  PolynomialXd third_derivative_y_;
};

}  // namespace planning
}  // namespace apollo

#endif  // MODULES_PLANNING_SMOOTHER_SPLINE_SMOOTHER_SPLINE2D_H_
