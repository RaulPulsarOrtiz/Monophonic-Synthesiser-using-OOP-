#pragma once
#include "../Source/FX/Tremolo.h"

class TremoloGui : public Component,
				   public Slider::Listener,
				   public Button::Listener

{
public:
	/** TremoloGui constructor */
	TremoloGui();

	/** TremoloGui destructor */
	~TremoloGui();
	
	/** Resize Components */
	void resized() override;
	
	void sliderValueChanged(Slider* slider) override;
	void buttonClicked(Button*) override;
	
	/** /** Set the Tremolo object for this Gui to control */
	void setTremolo(Tremolo*);
private:
	Tremolo* tremoloPtr { nullptr };
	TextButton tremoloButton;
	Slider tremoloFreqSldr, tremoloDepthSldr;
	Label tremoloFreqLabel, tremoloDepthLabel;
	float tremoloFreq = 0.f;
	float tDepthValue = 0.f;
};

