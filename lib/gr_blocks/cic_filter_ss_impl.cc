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
#include "cic_filter_ss_impl.h"

namespace gr {
  namespace cgsdr {

    cic_filter_ss::sptr
    cic_filter_ss::make(int decim)
    {
      return gnuradio::get_initial_sptr
        (new cic_filter_ss_impl(decim));
    }

    /*
     * The private constructor
     */
    cic_filter_ss_impl::cic_filter_ss_impl(int decim)
      : gr::sync_decimator("cic_filter_ss",
              gr::io_signature::make(1, 1, sizeof(int)),
              gr::io_signature::make(1, 1, sizeof(int)), decim)
    {}

    /*
     * Our virtual destructor.
     */
    cic_filter_ss_impl::~cic_filter_ss_impl()
    {
    }

    int
    cic_filter_ss_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      const int *in = (const int *) input_items[0];
      int *out = (int *) output_items[0];

      // Do <+signal processing+>

      int integrator1old = integrator1;

      for(int i = 0; i < noutput_items; i++)
      {
        for(unsigned int j = 0; j < decimation(); j++)
        {
          integrator1 += in[i*decimation() + j];
        }

        out[i] = (integrator1 - integrator1old);
        integrator1old = integrator1;
      }

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

  } /* namespace cgsdr */
} /* namespace gr */

