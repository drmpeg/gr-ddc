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

#ifndef INCLUDED_DDC_DDC_F_IMPL_H
#define INCLUDED_DDC_DDC_F_IMPL_H

#include <ddc/ddc_f.h>
#include <gnuradio/fxpt_nco.h>

namespace gr {
  namespace ddc {

    class ddc_f_impl : public ddc_f
    {
     private:
      double d_sampling_freq;
      double d_frequency;
      double d_ampl;
      gr::fxpt_nco d_nco1;
      gr::fxpt_nco d_nco2;

     public:
      ddc_f_impl(double sampling_freq, double frequency, double ampl);
      ~ddc_f_impl();

      void set_frequency(double frequency);

      // Where all the action really happens
      int work(int noutput_items,
         gr_vector_const_void_star &input_items,
         gr_vector_void_star &output_items);
    };

  } // namespace ddc
} // namespace gr

#endif /* INCLUDED_DDC_DDC_F_IMPL_H */

