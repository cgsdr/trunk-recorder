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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "cic_wrapper_impl.h"

namespace gr {
  namespace cgsdr {

    cic_wrapper::sptr
    cic_wrapper::make(int decim)
    {
      return gnuradio::get_initial_sptr
        (new cic_wrapper_impl(decim));
    }

    /*
     * The private constructor
     */
    cic_wrapper_impl::cic_wrapper_impl(int decim)
      : gr::hier_block2("cic_wrapper",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(gr_complex)))
    {
      
      cic_filter_real = cgsdr::cic_filter_ss::make(decim);
      cic_filter_imag = cgsdr::cic_filter_ss::make(decim);
      complex_to_float = gr::blocks::complex_to_float::make(1);
      float_to_int_real = gr::blocks::float_to_int::make(1, 1 << 15);
      float_to_int_imag = gr::blocks::float_to_int::make(1, 1 << 15);
      int_to_float_real = gr::blocks::int_to_float::make(1, 1);
      int_to_float_imag = gr::blocks::int_to_float::make(1, 1);
      float_to_complex = gr::blocks::float_to_complex::make(1);
      filter_gain = gr::blocks::multiply_const_cc::make(gr_complex(1.0/32768.0/decim,0));

      connect(self(), 0, complex_to_float, 0);
      connect(complex_to_float, 0, float_to_int_real, 0);
      connect(complex_to_float, 1, float_to_int_imag, 0);
      connect(float_to_int_real, 0, cic_filter_real, 0);
      connect(float_to_int_imag, 0, cic_filter_imag, 0);
      connect(cic_filter_real, 0, int_to_float_real, 0);
      connect(cic_filter_imag, 0, int_to_float_imag, 0);
      connect(int_to_float_real, 0, float_to_complex, 0);
      connect(int_to_float_imag, 0, float_to_complex, 1);
      connect(float_to_complex, 0, filter_gain, 0);
      connect(filter_gain, 0, self(), 0);
    }

    /*
     * Our virtual destructor.
     */
    cic_wrapper_impl::~cic_wrapper_impl()
    {
    }


  } /* namespace cgsdr */
} /* namespace gr */

