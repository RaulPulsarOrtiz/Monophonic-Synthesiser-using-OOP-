#include "MySynthGui.h"

MySynthGui::MySynthGui()
{
    oscMenu1.setText("waveform", dontSendNotification);
    oscMenu1.addItem("Sine Wave", 1);
    oscMenu1.addItem("Square Wave", 2);
    oscMenu1.addItem("Sawtooth Wave", 3);
    oscMenu1.addItem("Triangle", 4);
    oscMenu1.addListener(this);
    addAndMakeVisible(oscMenu1);
    
    oscMenu2.setText("waveform", dontSendNotification);
    oscMenu2.addItem("Sine Wave", 5);
    oscMenu2.addItem("Square Wave", 6);
    oscMenu2.addItem("Sawtooth Wave", 7);
    oscMenu2.addItem("Triangle", 8);
    oscMenu2.addListener(this);
    addAndMakeVisible(oscMenu2);

    gainSlider1.setSliderStyle(Slider::RotaryHorizontalDrag);
    gainSlider1.addListener(this);
    addAndMakeVisible(gainSlider1);

    gainSlider2.setSliderStyle(Slider::Rotary);
    gainSlider2.addListener(this);
    addAndMakeVisible(gainSlider2);

    harmonicsMenu.addItem("3rd Major", 1);
    harmonicsMenu.addItem("3rd minor", 2);
    harmonicsMenu.addItem("5th", 3);
    harmonicsMenu.addListener(this);
    addAndMakeVisible(harmonicsMenu);

    harmonicOscMenu.addItem("To OSC 1", 1);
    harmonicOscMenu.addItem("To OSC 2", 2);
    harmonicOscMenu.addListener(this);
    addAndMakeVisible(harmonicOscMenu);

    octOsc1.setText("Octave: ", dontSendNotification);
    octOsc1.addItem("+2 oct", 1);
    octOsc1.addItem("+1 oct", 2);
    octOsc1.addItem("0 oct", 3);
    octOsc1.addItem("-1 oct", 4);
    octOsc1.addItem("-2 oct", 5);
    octOsc1.addListener(this);
    addAndMakeVisible(octOsc1);

    octOsc2.setText("Octave: ", dontSendNotification);
    octOsc2.addItem("+2 oct", 1);
    octOsc2.addItem("+1 oct", 2);
    octOsc2.addItem("0 oct", 3);
    octOsc2.addItem("-2 oct", 4);
    octOsc2.addItem("-2 oct", 5);
    octOsc2.addListener(this);
    addAndMakeVisible(octOsc2);

    harmonicButton.setButtonText("Add Harmonics");
    addAndMakeVisible(harmonicButton);

    harmonicGainSldr.setSliderStyle(Slider::RotaryHorizontalDrag);
    harmonicGainSldr.addListener(this);
    addAndMakeVisible(harmonicGainSldr);

    osc1Label.setText("Oscillator 1:", juce::dontSendNotification);
    addAndMakeVisible(osc1Label);

    osc2Label.setText("Oscillator 2:", juce::dontSendNotification);
    addAndMakeVisible(osc2Label);
      
    harmonicOscLabel.setText("Harmonic Oscillator: ", juce::dontSendNotification);
    harmonicOscLabel.attachToComponent(&harmonicButton, false);
    addAndMakeVisible(harmonicOscLabel);

    harmonicGain.setText("Harmonic Gain: ", juce::dontSendNotification);
    harmonicGain.attachToComponent(&harmonicGainSldr, true);
    addAndMakeVisible(harmonicGain);

}

MySynthGui::~MySynthGui()
{

}

void MySynthGui::resized()
{
    oscMenu1.setBounds(10, 50, 100, 40);
    oscMenu2.setBounds(120, 50, 100, 40);

    gainSlider1.setBounds(10, 80, 130, 75);
    gainSlider2.setBounds(135, 80, 130, 75);

    octOsc1.setBounds(10, 150, 100, 40);
    octOsc2.setBounds(125, 150, 100, 40);

    harmonicsMenu.setBounds(120, 240, 100, 40);
    harmonicOscMenu.setBounds(120, 290, 100, 40);
    harmonicButton.setBounds(10, 260, 100, 40);
    harmonicGainSldr.setBounds(120, 325, 140, 90);

    osc1Label.setBounds(10, 25, 100, 40);
    osc2Label.setBounds(120, 25, 100, 40);
}

void MySynthGui::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == &oscMenu1)
        synthPtr->getOscType(oscMenu1.getSelectedId());
    if (comboBoxThatHasChanged == &oscMenu2)
        synthPtr->getOscType(oscMenu2.getSelectedId());

    if (comboBoxThatHasChanged == &harmonicsMenu)
        synthPtr->setHarmonicInterv(harmonicsMenu.getSelectedId());
    if (comboBoxThatHasChanged == &harmonicOscMenu)
        synthPtr->setHarmonicOsc(harmonicOscMenu.getSelectedId());

    if (comboBoxThatHasChanged == &octOsc1)
        synthPtr->setOctave(octOsc1.getSelectedId(), 0);
    if (comboBoxThatHasChanged == &octOsc2)
        synthPtr->setOctave(octOsc2.getSelectedId(), 1);
}


void MySynthGui::sliderValueChanged(Slider* slider)
{
    if (slider == &gainSlider1)
    {
        gainValue1 = gainSlider1.getValue();
        gainSlider1.setRange(0, 1);
        gainValue1 = gainValue1 * gainValue1 * gainValue1; //Making this gain Value exponential
        synthPtr->setGain1(gainValue1);
    }
    else if (slider == &gainSlider2)
    {
        gainValue2 = gainSlider2.getValue();
        gainSlider2.setRange(0, 1); //Range from 0 to 1
        gainValue2 = gainValue2 * gainValue2 * gainValue2; //Making this gain Value exponential
        synthPtr->setGain2(gainValue2);
    }
    else if (slider == &harmonicGainSldr)
    {
        gainHar = harmonicGainSldr.getValue();
        harmonicGainSldr.setRange(0, 1);
        gainHar = gainHar * gainHar * gainHar;  //Making this gain Value exponential
        synthPtr->setGainHar(gainHar);
    }
}

void MySynthGui::setSynth(MySynth* synthptr)
{ 
    synthPtr = synthptr;
}
   
void MySynthGui::buttonClicked(Button*)
{

}
   