#pragma once
#include <JuceHeader.h>
#include "../FX/Vibrato.h"

class VibratoGui : public Component,
				   public Slider::Listener,
				   public Button::Listener
{
public:
	/** MySynthGui constructor */
	VibratoGui();
	
	/** MySynthGui destructor */
	~VibratoGui();
	
	/** Resize Components */
	void resized() override;
	
	void sliderValueChanged(juce::Slider* slider) override;
	void buttonClicked(Button*) override;

	/** Set the Vibrato object for this Gui to control */
	void setVibrato(Vibrato*);
private:
	Vibrato* vibratoPtr { nullptr };
	Slider vibratoFreqSldr, vibratoDepthSldr;
	TextButton vibratoButton;
	Label vibratoFreqLabel, vibratoDepthLabel;
	float vibratoFreq = 0.f;
	float vibratoDepth = 0.f;
};

