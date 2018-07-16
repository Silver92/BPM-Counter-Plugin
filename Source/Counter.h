/*
  ==============================================================================

    Counter.h
    Created: 14 Jul 2018 4:48:30pm
    Author:  Silver

  ==============================================================================
*/

#pragma once
#include <sstream>
#include <iomanip>

using namespace std;

using namespace std::chrono;

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
        g.setFont (40.0f);
        g.drawFittedText (message, getLocalBounds().reduced (10, 0), Justification::centred, 4);
        
        g.setColour (getLookAndFeel().findColour (Label::textColourId));
        g.setFont (40.0f);
        g.drawFittedText (BPM_Display, getLocalBounds().reduced (10, 0), Justification::centredBottom, 4);
    }
    
    
    bool keyPressed(const KeyPress& k, Component* comp) override {
        if(k.getKeyCode() == KeyPress::spaceKey && k.isCurrentlyDown()) {
            countBeats();
            repaint();
        }
        return true;
    }
    
//    bool keyStateChanged(bool isKeyDown, Component* comp) override {
//        return true;
//    }
    
    void mouseDown (const MouseEvent& e) override {
        countBeats();
        repaint();
    }
    
private:
    void countBeats() {
        if (count == 0) {
            startTime = Time::getMillisecondCounterHiRes();
        }
        endTime = Time::getMillisecondCounterHiRes();
        count++;
        message = std::to_string(count);
        if(count == 8) {
            duration = (endTime - startTime)/(count-1);
            duration = 60*1000.0/duration;
            duration = round(duration, 1);
            BPM_Display = std::to_string(duration);
            BPM_Display = BPM_Display.substr(0, (BPM_Display.find_last_of(".")+2));
            count = 0;
        }
    }
    
    double round(double src, int bits)
    {
        stringstream ss;
        ss << fixed << setprecision(bits) << src;
        ss >> src;
        return src;
        
    }
    
private:
    double startTime;
    double endTime;
    double duration;
    int count = 0;
    std::string message {"This is the count display panel"};
    std::string BPM_Display {"This is the BPM display panel"};
    bool isKeyDown = false;
    
};
