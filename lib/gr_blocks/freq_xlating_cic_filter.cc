
#include "freq_xlating_cic_filter.h"

void freq_xlating_cic_filter::set_center_freq(double center_freq) {
  this->center_freq = center_freq;
  this->refresh();
}

freq_xlating_cic_filter_sptr make_freq_xlating_cic_filter(int decimation, double center_freq, double sampling_freq)
{
	return gnuradio::get_initial_sptr(new freq_xlating_cic_filter(decimation, center_freq, sampling_freq));
}

void freq_xlating_cic_filter::refresh() {
  const float pi = M_PI; //boost::math::constants::pi<double>();

  float phase_inc = (2.0 * pi * this->center_freq) / this->samp_rate;
  this->rotator->set_phase_inc(-1 * this->decim * phase_inc);
}

freq_xlating_cic_filter::~freq_xlating_cic_filter() {

}

freq_xlating_cic_filter::freq_xlating_cic_filter(int decim, double center_freq, double samp_rate)
	: gr::hier_block2 ("freq_xlating_cic_filter_ccc",
	                   gr::io_signature::make  (1, 1, sizeof(gr_complex)),
	                   gr::io_signature::make  (1, 1, sizeof(gr_complex)))
{

        this->decim  = decim;
        this->center_freq = center_freq;
        this->samp_rate   = samp_rate;

        this->filter =  gr::cgsdr::cic_wrapper::make(this->decim);
        this->rotator = gr::blocks::rotator_cc::make(0.0);
        connect(self(),0, rotator,0);
        connect(rotator,0, filter, 0);
        connect(filter,0, self(),0);

        // Refresh
        this->refresh();
}
