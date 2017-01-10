/* -*- c++ -*- */
/* 
 * Copyright 2017 Ron Economos.
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


#ifndef INCLUDED_DDC_DDC_F_H
#define INCLUDED_DDC_DDC_F_H

#include <ddc/api.h>
#include <gnuradio/sync_block.h>

namespace gr {
  namespace ddc {

    /*!
     * \brief <+description of block+>
     * \ingroup ddc
     *
     */
    class DDC_API ddc_f : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<ddc_f> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of ddc::ddc_f.
       *
       * To avoid accidental use of raw pointers, ddc::ddc_f's
       * constructor is in a private implementation
       * class. ddc::ddc_f::make is the public interface for
       * creating new instances.
       */
      static sptr make(double sampling_freq, double frequency, double ampl);
    };

  } // namespace ddc
} // namespace gr

#endif /* INCLUDED_DDC_DDC_F_H */

