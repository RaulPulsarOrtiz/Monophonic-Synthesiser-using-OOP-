#pragma once
#include <JuceHeader.h>
#include "../audio/MySynth.h"

class MySynthGui :  public Component,
					public ComboBox::Listener,
					public Slider::Listener,
					public Button::Listener
{
public:
	/** MySynthGui constructor */
	MySynthGui();
	
	/** MySynthGui destructor */
	~MySynthGui();

	/** Resize Components */
	void resized() override;
	
	void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;
	void sliderValueChanged(Slider* slider) override;
	
	/** Set the MySynth object for this Gui to control */
	void setSynth(MySynth*);
	
	void buttonClicked(Button*) override;
	
private:
	MySynth* synthPtr {nullptr}; 
	ComboBox oscMenu1, oscMenu2, harmonicsMenu, harmonicOscMenu, octOsc1, octOsc2;
	Slider gainSlider1, gainSlider2, harmonicGainSldr;
	TextButton harmonicButton;
	Label osc1Label, osc2Label, harmonicOscLabel, harmonicGain;
	float gainValue1 = 0.f;
	float gainValue2 = 0.f;
	float gainHar = 0.f;

	int noteOffset1 = 0;
	int noteOffset2 = 0;
};

