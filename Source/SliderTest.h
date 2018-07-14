/*
  ==============================================================================

    SliderTest.h
    Created: 13 Jul 2018 9:58:15pm
    Author:  Silver

  ==============================================================================
*/

#pragma once

struct SnappingSlider  : public Slider
{
    double snapValue (double attemptedValue, DragMode dragMode) override
    {
        if (dragMode == notDragging)
            return attemptedValue;  // if they're entering the value in the text-box, don't mess with it.
        
        if (attemptedValue > 40 && attemptedValue < 60)
            return 50.0;
        
        return attemptedValue;
    }
};

struct SlidersPage  : public Component
{
    SlidersPage()
    {
        Rectangle<int> layoutArea { 20, 20, 580, 430 };
        auto sliderArea = layoutArea.removeFromTop (320);
        
        auto* s = createSlider (false);
        s->setSliderStyle (Slider::LinearVertical);
        s->setTextBoxStyle (Slider::TextBoxBelow, false, 100, 20);
        s->setBounds (sliderArea.removeFromLeft (70));
        s->setDoubleClickReturnValue (true, 50.0); // double-clicking this slider will set it to 50.0
        s->setTextValueSuffix (" units");
        
        s = createSlider (false);
        s->setSliderStyle (Slider::LinearVertical);
        s->setVelocityBasedMode (true);
        s->setSkewFactor (0.5);
        s->setTextBoxStyle (Slider::TextBoxAbove, true, 100, 20);
        s->setBounds (sliderArea.removeFromLeft (70));
        s->setTextValueSuffix (" rels");
        
        sliderArea.removeFromLeft (20);
        auto horizonalSliderArea = sliderArea.removeFromLeft (180);
        
        s = createSlider (true);
        s->setSliderStyle (Slider::LinearHorizontal);
        s->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
        s->setBounds (horizonalSliderArea.removeFromTop (20));
        
        s = createSlider (false);
        s->setSliderStyle (Slider::LinearHorizontal);
        s->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        horizonalSliderArea.removeFromTop (20);
        s->setBounds (horizonalSliderArea.removeFromTop (20));
        s->setPopupDisplayEnabled (true, false, this);
        s->setTextValueSuffix (" nuns required to change a lightbulb");
        
        s = createSlider (false);
        s->setSliderStyle (Slider::LinearHorizontal);
        s->setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxAbove, false, 70, 20);
        horizonalSliderArea.removeFromTop (20);
        s->setBounds (horizonalSliderArea.removeFromTop (50));
        s->setPopupDisplayEnabled (true, false, this);
        
        s = createSlider (false);
        s->setSliderStyle (Slider::IncDecButtons);
        s->setTextBoxStyle (Slider::TextBoxLeft, false, 50, 20);
        horizonalSliderArea.removeFromTop (20);
        s->setBounds (horizonalSliderArea.removeFromTop (20));
        s->setIncDecButtonsMode (Slider::incDecButtonsDraggable_Vertical);
        
        s = createSlider (false);
        s->setSliderStyle (Slider::Rotary);
        s->setRotaryParameters (MathConstants<float>::pi * 1.2f, MathConstants<float>::pi * 2.8f, false);
        s->setTextBoxStyle (Slider::TextBoxRight, false, 70, 20);
        horizonalSliderArea.removeFromTop (15);
        s->setBounds (horizonalSliderArea.removeFromTop (70));
        s->setTextValueSuffix (" mm");
        
        s = createSlider (false);
        s->setSliderStyle (Slider::LinearBar);
        horizonalSliderArea.removeFromTop (10);
        s->setBounds (horizonalSliderArea.removeFromTop (30));
        s->setTextValueSuffix (" gallons");
        
        sliderArea.removeFromLeft (20);
        auto twoValueSliderArea = sliderArea.removeFromLeft (180);
        
        s = createSlider (false);
        s->setSliderStyle (Slider::TwoValueHorizontal);
        s->setBounds (twoValueSliderArea.removeFromTop (40));
        
        s = createSlider (false);
        s->setSliderStyle (Slider::ThreeValueHorizontal);
        s->setPopupDisplayEnabled (true, false, this);
        twoValueSliderArea.removeFromTop (10);
        s->setBounds (twoValueSliderArea.removeFromTop (40));
        
        s = createSlider (false);
        s->setSliderStyle (Slider::TwoValueVertical);
        twoValueSliderArea.removeFromLeft (30);
        s->setBounds (twoValueSliderArea.removeFromLeft (40));
        
        s = createSlider (false);
        s->setSliderStyle (Slider::ThreeValueVertical);
        s->setPopupDisplayEnabled (true, false, this);
        twoValueSliderArea.removeFromLeft (30);
        s->setBounds (twoValueSliderArea.removeFromLeft (40));
        
        s = createSlider (false);
        s->setSliderStyle (Slider::LinearBarVertical);
        s->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
        sliderArea.removeFromLeft (20);
        s->setBounds (sliderArea.removeFromLeft (20));
        s->setPopupDisplayEnabled (true, true, this);
        s->setTextValueSuffix (" mickles in a muckle");
        
        /* Here, we'll create a Value object, and tell a bunch of our sliders to use it as their
         value source. By telling them all to share the same Value, they'll stay in sync with
         each other.
         
         We could also optionally keep a copy of this Value elsewhere, and by changing it,
         cause all the sliders to automatically update.
         */
        Value sharedValue;
        sharedValue = Random::getSystemRandom().nextDouble() * 100;
        for (int i = 0; i < 8; ++i)
            sliders.getUnchecked (i)->getValueObject().referTo (sharedValue);
        
        // ..and now we'll do the same for all our min/max slider values..
        Value sharedValueMin, sharedValueMax;
        sharedValueMin = Random::getSystemRandom().nextDouble() * 40.0;
        sharedValueMax = Random::getSystemRandom().nextDouble() * 40.0 + 60.0;
        
        for (int i = 8; i <= 11; ++i)
        {
            auto* selectedSlider = sliders.getUnchecked(i);
            selectedSlider->setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
            selectedSlider->getMaxValueObject().referTo (sharedValueMax);
            selectedSlider->getMinValueObject().referTo (sharedValueMin);
        }
        
        hintLabel.setBounds (layoutArea);
        addAndMakeVisible (hintLabel);
    }
public:
    void viewSliders() {
        for(int i = 0; i < sliders.size(); i++ ) {
            addAndMakeVisible(*sliders[i]);
        }
    }
    
private:
    OwnedArray<Slider> sliders;
    Label hintLabel  { "hint", "Try right-clicking on a slider for an options menu. \n\n"
        "Also, holding down CTRL while dragging will turn on a slider's velocity-sensitive mode" };
    
    Slider* createSlider (bool isSnapping)
    {
        auto* s = isSnapping ? (new SnappingSlider()) : (new Slider());
        sliders.add (s);
        addAndMakeVisible (s);
        s->setRange (0.0, 100.0, 0.1);
        s->setPopupMenuEnabled (true);
        s->setValue (Random::getSystemRandom().nextDouble() * 100.0, dontSendNotification);
        return s;
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlidersPage)
};
