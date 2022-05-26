/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainComponent::MainComponent(Audio& a) : audio(a)
                                       
{
    setSize(800, 600);
    synthGui.setSynth(audio.getSynth());
    vibratoGui.setVibrato(audio.getVibrato());
    tremoloGui.setTremolo(audio.getTremolo());    

    addAndMakeVisible(synthGui);
    addAndMakeVisible(tremoloGui);
    addAndMakeVisible(vibratoGui); 
      
   midiSelector.setText("Midi:", dontSendNotification);
   addAndMakeVisible(midiSelector);
   midiSelector.setTextWhenNoChoicesAvailable("No MIDI Inputs Enabled");

   midiSelector.addItemList(audio.midiInputNames, 1);
   midiSelector.onChange = [this] { audio.setMidiInput(midiSelector.getSelectedItemIndex()); };
   midiSelector.setSelectedId(midiSelector.getSelectedItemIndex() + 1, juce::dontSendNotification);
   
   addAndMakeVisible(setMidiSelectorText);
   setMidiSelectorText.setText("Select Midi Input Port:", dontSendNotification);
}

MainComponent::~MainComponent()
{

}


//==============================================================================


void MainComponent::resized()
{
    Rectangle<int> area = getLocalBounds();
    Rectangle<int> synthArea = area.removeFromLeft(getWidth() / 2);
    Rectangle<int> tremoloArea = area.removeFromLeft(getWidth() / 4);
    Rectangle<int> vibratoArea = area.removeFromLeft(getWidth() / 4);
    Rectangle<int> midiSelectorArea = vibratoArea.removeFromBottom(getHeight() / 8);
    Rectangle<int> labelMidiSelectorArea = vibratoArea.removeFromBottom(getHeight() / 7);
        // Rectangle<int> areaKeyboard = area.removeFromBottom(getHeight() / 5); No midiKeyboard Component in this version

    synthGui.setBounds(synthArea);
    tremoloGui.setBounds(tremoloArea);
    vibratoGui.setBounds(vibratoArea);
    midiSelector.setBounds (midiSelectorArea);
    setMidiSelectorText.setBounds(labelMidiSelectorArea);
}

void MainComponent::paint(Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
    Rectangle<int> area = getLocalBounds();
    Rectangle<int> synthArea = area.removeFromLeft(getWidth() / 2);
    Rectangle<int> tremoloArea = area.removeFromLeft(getWidth() / 4);
    Rectangle<int> vibratoArea = area.removeFromLeft(getWidth() / 4);
    Rectangle<int> midiSelectorArea = vibratoArea.removeFromBottom(getHeight() / 8);
    g.setColour(Colours::red);
    g.drawRect(synthArea);
    g.drawRect(tremoloArea);
    g.drawRect(vibratoArea);
    g.drawRect(midiSelectorArea);
}


//MenuBarCallbacks==============================================================
StringArray MainComponent::getMenuBarNames()
{
    auto names = { "File" };
    return StringArray(names);
}

PopupMenu MainComponent::getMenuForIndex(int topLevelMenuIndex, const String& menuName)
{
    PopupMenu menu;
    if (topLevelMenuIndex == 0)
        menu.addItem(AudioPrefs, "Audio Prefrences", true, false);
    return menu;
}

void MainComponent::menuItemSelected(int menuItemID, int topLevelMenuIndex)
{
    if (topLevelMenuIndex == FileMenu)
    {
        if (menuItemID == AudioPrefs)
        {
            DialogWindow::LaunchOptions la;
            la.dialogTitle = "Audio Settings";
            OptionalScopedPointer<Component> osp(std::make_unique<AudioDeviceSelectorComponent>
                (audio.getAudioDeviceManager(),
                    1, 2, 2, 2,
                    true, true, true, false));
            osp->setSize(450, 350);
            la.content = std::move(osp);
            la.componentToCentreAround = this;
            la.launchAsync();
        }
    }
}


