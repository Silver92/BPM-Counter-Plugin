/*
  ==============================================================================

    Counter.h
    Created: 14 Jul 2018 4:48:30pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

class BPMCounter: public Component, KeyListener {
public:
    BPMCounter() {
        setWantsKeyboardFocus(true);
        addKeyListener(this);
    }
    
    ~BPMCounter() {
        removeKeyListener(this);
    }
    
    void paint (Graphics& g) override
    {
        g.setColour (getLookAndFeel().findColour (Label::textColourId));
        g.setFont (14.0f);
        g.drawFittedText (message, getLocalBounds().reduced (10, 0), Justification::centred, 4);
    }
    
    
    bool keyPressed(const KeyPress& k, Component* comp) override {
        if(k.getKeyCode() == KeyPress::spaceKey) {
            message = "Space pressed";
        }
        repaint();
        return true;
    }
    
    
    void mouseDown (const MouseEvent& e) override {
        lastMousePosition = e.position;
        message = String(e.position.x);
        repaint();
    }
    
    String message {"This is the massage"};
    
private:
    
    Point<float> lastMousePosition;
};
