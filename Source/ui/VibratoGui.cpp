#include "VibratoGui.h"

VibratoGui::VibratoGui()
{
    vibratoButton.setButtonText("Vibrato");
    addAndMakeVisible(vibratoButton);

    vibratoFreqSldr.setSliderStyle(Slider::RotaryHorizontalDrag);
    vibratoFreqSldr.addListener(this);
    vibratoFreqSldr.setTextValueSuffix(" Hz");
    addAndMakeVisible(vibratoFreqSldr);

    vibratoDepthSldr.setSliderStyle(Slider::RotaryHorizontalDrag);
    vibratoDepthSldr.addListener(this);
    vibratoDepthSldr.setTextValueSuffix(" %");
    vibratoDepthSldr.setValue(0.5);
    addAndMakeVisible(vibratoDepthSldr);

    vibratoFreqLabel.setText("V Frequency: ", juce::dontSendNotification);
    addAndMakeVisible(vibratoFreqLabel);
    vibratoDepthLabel.setText("V Depth: ", juce::dontSendNotification);
    addAndMakeVisible(vibratoDepthLabel);
}

VibratoGui::~VibratoGui()
{

}

void VibratoGui::resized()
{
    vibratoButton.setBounds(10, 50, 120, 20);
    vibratoFreqLabel.setBounds(10, 100, 120, 20);
    vibratoFreqSldr.setBounds(10, 90, 140, 95);
    vibratoDepthLabel.setBounds(10, 180, 120, 20);
    vibratoDepthSldr.setBounds(10, 170, 140, 95);
}

void VibratoGui::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &vibratoFreqSldr)
    {
        vibratoFreq = vibratoFreqSldr.getValue();
        vibratoFreqSldr.setRange(0, 20);
        vibratoPtr->setVibratoFreq(vibratoFreq);
    }
    else if (slider == &vibratoDepthSldr)
    {
        vibratoDepth = vibratoDepthSldr.getValue();
        vibratoDepthSldr.setRange(0, 1);
        vibratoPtr->setVibratoDepth(vibratoDepth);
    }
}

void VibratoGui::buttonClicked(Button* button)
{

}

void VibratoGui::setVibrato(Vibrato* vibratoptr)
{
    vibratoPtr = vibratoptr;
}