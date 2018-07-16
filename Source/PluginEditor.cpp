/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Bpm_counterAudioProcessorEditor::Bpm_counterAudioProcessorEditor (Bpm_counterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize(800, 600);
    addAndMakeVisible(counter);
}

Bpm_counterAudioProcessorEditor::~Bpm_counterAudioProcessorEditor()
{
}

//==============================================================================

void Bpm_counterAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll(Colour::greyLevel(0.5));
}

void Bpm_counterAudioProcessorEditor::resized()
{
    counter.setBounds(getLocalBounds());
}





