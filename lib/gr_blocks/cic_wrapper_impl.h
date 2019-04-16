/* -*- c++ -*- */
/* 
 * Copyright 2019 CGSDR.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_CGSDR_CIC_WRAPPER_IMPL_H
#define INCLUDED_CGSDR_CIC_WRAPPER_IMPL_H

#include "cic_wrapper.h"
#include "cic_filter_ss.h"
#include <gnuradio/blocks/complex_to_float.h>
#include <gnuradio/blocks/float_to_complex.h>
#include <gnuradio/blocks/float_to_int.h>
#include <gnuradio/blocks/int_to_float.h>
#include <gnuradio/blocks/multiply_const_cc.h>

namespace gr {
  namespace cgsdr {

    class cic_wrapper_impl : public cic_wrapper
    {
     private:
      // Nothing to declare in this block.
      cgsdr::cic_filter_ss::sptr cic_filter_real;
      cgsdr::cic_filter_ss::sptr cic_filter_imag;
      gr::blocks::complex_to_float::sptr complex_to_float;
      gr::blocks::float_to_int::sptr float_to_int_real;
      gr::blocks::float_to_int::sptr float_to_int_imag;
      gr::blocks::int_to_float::sptr int_to_float_real;
      gr::blocks::int_to_float::sptr int_to_float_imag;
      gr::blocks::float_to_complex::sptr float_to_complex;
      gr::blocks::multiply_const_cc::sptr filter_gain;

     public:
      cic_wrapper_impl(int decim);
      ~cic_wrapper_impl();

      // Where all the action really happens
    };

  } // namespace cgsdr
} // namespace gr

#endif /* INCLUDED_CGSDR_CIC_WRAPPER_IMPL_H */

