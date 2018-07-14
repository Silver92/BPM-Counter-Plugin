/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

#include "SliderTest.h"

//==============================================================================
/**
*/
class Bpm_counterAudioProcessorEditor  : public AudioProcessorEditor, KeyListener
{
public:
    Bpm_counterAudioProcessorEditor (Bpm_counterAudioProcessor&);
    ~Bpm_counterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    //==============================================================================
    // My addings
    void mouseDown (const MouseEvent& e) override;
    bool keyPressed(const KeyPress& k, Component* comp) override;

//    bool keyStateChanged(bool isKeyDown) override;
    String message {"This is the massage"};

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Bpm_counterAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Bpm_counterAudioProcessorEditor)
    
    //==============================================================================
    // My addings
    SlidersPage slider;
    Point<float> lastMousePosition;
    
    
};
