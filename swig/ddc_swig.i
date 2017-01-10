/* -*- c++ -*- */

#define DDC_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "ddc_swig_doc.i"

%{
#include "ddc/ddc_f.h"
%}


%include "ddc/ddc_f.h"
GR_SWIG_BLOCK_MAGIC2(ddc, ddc_f);
