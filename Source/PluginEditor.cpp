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
    setWantsKeyboardFocus(true);
    addKeyListener(this);
}

Bpm_counterAudioProcessorEditor::~Bpm_counterAudioProcessorEditor()
{
}

//==============================================================================

void Bpm_counterAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    g.setColour (Colours::white);
    
    auto radius = 20;
    g.setColour (Colours::lightgreen);
    g.fillEllipse  (jmax (0.0f, lastMousePosition.x) - radius / 2.0f,
                    jmax (0.0f, lastMousePosition.y) - radius / 2.0f,
                    radius, radius);
    
    
    g.setColour (getLookAndFeel().findColour (Label::textColourId));
    g.setFont (14.0f);
    g.drawFittedText (message, getLocalBounds().reduced (10, 0), Justification::centred, 4);
}

void Bpm_counterAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void Bpm_counterAudioProcessorEditor::mouseDown(const MouseEvent &e) {
    lastMousePosition = e.position;
    message = String(e.position.x);
    repaint();
}

bool Bpm_counterAudioProcessorEditor::keyPressed(const juce::KeyPress &k, Component* comp) {
    if(k.getKeyCode() == KeyPress::spaceKey) {
        message = "Space pressed";
    }
    repaint();
    return true;
}

//bool Bpm_counterAudioProcessorEditor::keyStateChanged(bool isKeyDown) { 
//    return true;
//}






