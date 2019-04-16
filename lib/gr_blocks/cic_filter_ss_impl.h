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

#ifndef INCLUDED_CGSDR_CIC_FILTER_SS_IMPL_H
#define INCLUDED_CGSDR_CIC_FILTER_SS_IMPL_H

#include "cic_filter_ss.h"

namespace gr {
  namespace cgsdr {

    class cic_filter_ss_impl : public cic_filter_ss
    {
     private:
      // Nothing to declare in this block.
      int integrator1;

     public:
      cic_filter_ss_impl(int decim);
      ~cic_filter_ss_impl();

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace cgsdr
} // namespace gr

#endif /* INCLUDED_CGSDR_CIC_FILTER_SS_IMPL_H */

