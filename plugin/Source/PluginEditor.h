/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_8D971FE651240F9F__
#define __JUCE_HEADER_8D971FE651240F9F__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StageDirectorAudioProcessorEditor  : public AudioProcessorEditor,
                                           public Timer,
                                           public SliderListener,
                                           public ComboBoxListener,
                                           public ButtonListener
{
public:
    //==============================================================================
    StageDirectorAudioProcessorEditor (StageDirectorAudioProcessor& ownerFilter);
    ~StageDirectorAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    StageDirectorAudioProcessor* getProcessor() const{
        return static_cast<StageDirectorAudioProcessor*>(getAudioProcessor());}
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> titleLabel;
    ScopedPointer<ComboBox> windowTypeSelector;
    ScopedPointer<Label> windowLabel;
    ScopedPointer<Slider> fftSizeSldier;
    ScopedPointer<Label> sizeLabel;
    ScopedPointer<Slider> hopSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> centroidBox;
    ScopedPointer<Label> centroidLabel;
    ScopedPointer<Label> amplitudeBox;
    ScopedPointer<Label> amplitudeLabel;
    ScopedPointer<ToggleButton> bypassButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StageDirectorAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_8D971FE651240F9F__
