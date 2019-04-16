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


#ifndef INCLUDED_CGSDR_CIC_FILTER_SS_H
#define INCLUDED_CGSDR_CIC_FILTER_SS_H

#include <gnuradio/attributes.h>
#include <gnuradio/sync_decimator.h>

namespace gr {
  namespace cgsdr {

    /*!
     * \brief <+description of block+>
     * \ingroup cgsdr
     *
     */
    class cic_filter_ss : virtual public gr::sync_decimator
    {
     public:
      typedef boost::shared_ptr<cic_filter_ss> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of cgsdr::cic_filter_ss.
       *
       * To avoid accidental use of raw pointers, cgsdr::cic_filter_ss's
       * constructor is in a private implementation
       * class. cgsdr::cic_filter_ss::make is the public interface for
       * creating new instances.
       */
      static sptr make(int decim);
    };

  } // namespace cgsdr
} // namespace gr

#endif /* INCLUDED_CGSDR_CIC_FILTER_SS_H */

