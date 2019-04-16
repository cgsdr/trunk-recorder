#ifndef INCLUDED_GR_XLATING_FIR_FILTER_H
#define INCLUDED_GR_XLATING_FIR_FILTER_H
#include <math.h>

#include <gnuradio/blocks/api.h>
#include <gnuradio/io_signature.h>
#include <gnuradio/hier_block2.h>
// #include <gnuradio/filter/fir_filter_ccc.h>
#include <gnuradio/blocks/rotator_cc.h>
#include "cic_wrapper.h"



class freq_xlating_cic_filter;
typedef boost::shared_ptr<freq_xlating_cic_filter> freq_xlating_cic_filter_sptr;
freq_xlating_cic_filter_sptr make_freq_xlating_cic_filter(int decimation, double center_freq, double samp_rate);

class freq_xlating_cic_filter : public gr::hier_block2 {

  friend freq_xlating_cic_filter_sptr make_freq_xlating_cic_filter(int decimation, double center_freq, double samp_rate);

    gr::blocks::rotator_cc::sptr rotator;
    gr::cgsdr::cic_wrapper::sptr filter;
    int decim;
    double center_freq;
    double samp_rate;

    void refresh();

    ~freq_xlating_cic_filter();

    freq_xlating_cic_filter(int decimation, double center_freq, double sampling_freq);
public:
    void set_center_freq( double center_freq);
};

#endif
