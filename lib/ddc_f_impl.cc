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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "ddc_f_impl.h"

namespace gr {
  namespace ddc {

    ddc_f::sptr
    ddc_f::make(double sampling_freq, double frequency, double ampl)
    {
      return gnuradio::get_initial_sptr
        (new ddc_f_impl(sampling_freq, frequency, ampl));
    }

    /*
     * The private constructor
     */
    ddc_f_impl::ddc_f_impl(double sampling_freq, double frequency, double ampl)
      : gr::sync_block("ddc_f",
              gr::io_signature::make(0, 0, 0),
              gr::io_signature::make(2, 2, sizeof(float))),
      d_sampling_freq(sampling_freq),
      d_frequency(frequency), d_ampl(ampl)
    {
      set_frequency(frequency);
    }

    /*
     * Our virtual destructor.
     */
    ddc_f_impl::~ddc_f_impl()
    {
    }

    int
    ddc_f_impl::work(int noutput_items,
        gr_vector_const_void_star &input_items,
        gr_vector_void_star &output_items)
    {
      float *out1 = (float *) output_items[0];
      float *out2 = (float *) output_items[1];

      d_nco1.sin(out1, noutput_items, d_ampl);
      d_nco2.cos(out2, noutput_items, d_ampl);

      // Tell runtime system how many output items we produced.
      return noutput_items;
    }

    void
    ddc_f_impl::set_frequency(double frequency)
    {
      d_frequency = frequency;
      d_nco1.set_freq(2 * M_PI * d_frequency / d_sampling_freq);
      d_nco2.set_freq(2 * M_PI * d_frequency / d_sampling_freq);
    }

  } /* namespace ddc */
} /* namespace gr */

