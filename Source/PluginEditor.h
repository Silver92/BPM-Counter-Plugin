/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Counter.h"


//==============================================================================
/**
*/
class Bpm_counterAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    Bpm_counterAudioProcessorEditor (Bpm_counterAudioProcessor&);
    ~Bpm_counterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //==============================================================================
    // My addings
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Bpm_counterAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Bpm_counterAudioProcessorEditor)
    
    //==============================================================================
    // My addings
    
    BPMCounter counter;
};
