#include "TremoloGui.h"
#include <JuceHeader.h>

TremoloGui::TremoloGui()
{
    tremoloButton.setButtonText("Tremolo");
    addAndMakeVisible(tremoloButton);

    tremoloFreqSldr.setSliderStyle(Slider::RotaryHorizontalDrag);
    tremoloFreqSldr.addListener(this);
    tremoloFreqSldr.setTextValueSuffix(" Hz");
    addAndMakeVisible(tremoloFreqSldr);

    tremoloDepthSldr.setSliderStyle(Slider::Rotary);
    tremoloDepthSldr.addListener(this);
    tremoloDepthSldr.setTextValueSuffix(" %");
    tremoloDepthSldr.setValue(0.5);
    addAndMakeVisible(tremoloDepthSldr);

    tremoloFreqLabel.setText("T Frequency: ", juce::dontSendNotification);
    addAndMakeVisible(tremoloFreqLabel);
    tremoloDepthLabel.setText("T Depth: ", juce::dontSendNotification);
    addAndMakeVisible(tremoloDepthLabel);

}

TremoloGui::~TremoloGui()
{

}

void TremoloGui::resized()
{
        tremoloButton.setBounds(10, 50, 120, 20);
        tremoloFreqLabel.setBounds(10, 100, 120, 20);
        tremoloFreqSldr.setBounds(10, 90, 140, 95);
        tremoloDepthLabel.setBounds(10, 180, 120, 20);
        tremoloDepthSldr.setBounds(10, 170, 140, 95);        
}

void TremoloGui::sliderValueChanged(Slider* slider)
{
    if (slider == &tremoloFreqSldr)
    {
        tremoloFreq = tremoloFreqSldr.getValue();
       
        tremoloFreqSldr.setRange(0, 20);
        tremoloPtr->setTremoloFreq(tremoloFreq);
    }
    else if (slider == &tremoloDepthSldr)
    {
        tDepthValue = tremoloDepthSldr.getValue();
        tremoloDepthSldr.setRange(0, 1);
        tremoloPtr->setTremoloDepth(tDepthValue);
    }
}

void TremoloGui::buttonClicked(Button* button)
{

}

void TremoloGui::setTremolo(Tremolo* tremoloptr)
{
    tremoloPtr = tremoloptr;
}