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
    }
    
    
    bool keyPressed(const KeyPress& k, Component* comp) override {
        if(k.getKeyCode() == KeyPress::spaceKey) {
            countBeats();
        }
        repaint();
        return true;
    }
    
    void mouseDown (const MouseEvent& e) override {
        countBeats();
        repaint();
    }
    
private:
    void countBeats() {
        timeCount.add(Time::getMillisecondCounterHiRes());
        count++;
        message = std::to_string(count);
        if(count == 8) {
            time = (timeCount.getLast()-timeCount.getFirst())/(count-1);
            time = 60*1000.0/time;
            time = round(time, 1);
            message = std::to_string(time);
            message = message.substr(0, (message.find_last_of(".")+2));
            timeCount.clear();
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
    double time;
    Array<double> timeCount;
    int count = 0;
    std::string message {"This is the massage"};
    
};
