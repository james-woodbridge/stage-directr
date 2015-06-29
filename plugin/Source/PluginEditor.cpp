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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StageDirectorAudioProcessorEditor::StageDirectorAudioProcessorEditor (StageDirectorAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (titleLabel = new Label ("Plugin Title",
                                               TRANS("Stage Director")));
    titleLabel->setFont (Font ("Avenir", 53.00f, Font::plain));
    titleLabel->setJustificationType (Justification::centred);
    titleLabel->setEditable (false, false, false);
    titleLabel->setColour (Label::backgroundColourId, Colour (0xff4d4d4d));
    titleLabel->setColour (Label::textColourId, Colour (0xfb00c7ed));
    titleLabel->setColour (Label::outlineColourId, Colour (0xff007c94));
    titleLabel->setColour (TextEditor::textColourId, Colours::black);
    titleLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (windowTypeSelector = new ComboBox ("Window Function Selection"));
    windowTypeSelector->setEditableText (false);
    windowTypeSelector->setJustificationType (Justification::centred);
    windowTypeSelector->setTextWhenNothingSelected (TRANS("Select"));
    windowTypeSelector->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    windowTypeSelector->addItem (TRANS("Rectangular"), 1);
    windowTypeSelector->addItem (TRANS("Bartlett"), 2);
    windowTypeSelector->addItem (TRANS("Hanning"), 3);
    windowTypeSelector->addItem (TRANS("Hamming"), 4);
    windowTypeSelector->addListener (this);

    addAndMakeVisible (windowLabel = new Label ("Window Label",
                                                TRANS("Window Function")));
    windowLabel->setFont (Font (15.00f, Font::plain));
    windowLabel->setJustificationType (Justification::centred);
    windowLabel->setEditable (false, false, false);
    windowLabel->setColour (Label::textColourId, Colour (0xff00c7ed));
    windowLabel->setColour (TextEditor::textColourId, Colours::black);
    windowLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (fftSizeSldier = new Slider ("FFT Size Slider"));
    fftSizeSldier->setRange (0, 16384, 128);
    fftSizeSldier->setSliderStyle (Slider::LinearHorizontal);
    fftSizeSldier->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 14);
    fftSizeSldier->setColour (Slider::thumbColourId, Colour (0xff00c7ed));
    fftSizeSldier->setColour (Slider::trackColourId, Colour (0x8b00374f));
    fftSizeSldier->setColour (Slider::textBoxTextColourId, Colours::white);
    fftSizeSldier->setColour (Slider::textBoxBackgroundColourId, Colour (0xff4d4d4d));
    fftSizeSldier->setColour (Slider::textBoxHighlightColourId, Colour (0x00000000));
    fftSizeSldier->setColour (Slider::textBoxOutlineColourId, Colour (0xff377c94));
    fftSizeSldier->addListener (this);

    addAndMakeVisible (sizeLabel = new Label ("FFT Size Label",
                                              TRANS("FFT Size (samples)")));
    sizeLabel->setFont (Font (15.00f, Font::plain));
    sizeLabel->setJustificationType (Justification::centred);
    sizeLabel->setEditable (false, false, false);
    sizeLabel->setColour (Label::textColourId, Colour (0xff00c7ed));
    sizeLabel->setColour (TextEditor::textColourId, Colours::black);
    sizeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (hopSlider = new Slider ("Hop Size Slider"));
    hopSlider->setRange (0, 8192, 128);
    hopSlider->setSliderStyle (Slider::LinearHorizontal);
    hopSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 14);
    hopSlider->setColour (Slider::thumbColourId, Colour (0xff00c7ed));
    hopSlider->setColour (Slider::trackColourId, Colour (0x8b00374f));
    hopSlider->setColour (Slider::textBoxTextColourId, Colours::white);
    hopSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0xff4d4d4d));
    hopSlider->setColour (Slider::textBoxOutlineColourId, Colour (0xff007c94));
    hopSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Hop Size (samples)")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xff00c7ed));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (centroidBox = new Label ("Centroid Value",
                                                TRANS("0")));
    centroidBox->setFont (Font (69.40f, Font::plain));
    centroidBox->setJustificationType (Justification::centred);
    centroidBox->setEditable (false, false, false);
    centroidBox->setColour (Label::backgroundColourId, Colour (0xff4d4d4d));
    centroidBox->setColour (Label::textColourId, Colour (0xff00c7ed));
    centroidBox->setColour (Label::outlineColourId, Colour (0xff007c94));
    centroidBox->setColour (TextEditor::textColourId, Colours::black);
    centroidBox->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (centroidLabel = new Label ("Centroid Label",
                                                  TRANS("Spectral Centroid")));
    centroidLabel->setFont (Font (15.00f, Font::plain));
    centroidLabel->setJustificationType (Justification::centred);
    centroidLabel->setEditable (false, false, false);
    centroidLabel->setColour (Label::textColourId, Colour (0xff00c7ed));
    centroidLabel->setColour (TextEditor::textColourId, Colours::black);
    centroidLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (amplitudeBox = new Label ("Average Amplitude Value",
                                                 TRANS("0")));
    amplitudeBox->setFont (Font (69.40f, Font::plain));
    amplitudeBox->setJustificationType (Justification::centred);
    amplitudeBox->setEditable (false, false, false);
    amplitudeBox->setColour (Label::backgroundColourId, Colour (0xff4d4d4d));
    amplitudeBox->setColour (Label::textColourId, Colour (0xff00c7ed));
    amplitudeBox->setColour (Label::outlineColourId, Colour (0xff007c94));
    amplitudeBox->setColour (TextEditor::textColourId, Colours::black);
    amplitudeBox->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (amplitudeLabel = new Label ("Average Amplitude Label",
                                                   TRANS("Amplitude Level")));
    amplitudeLabel->setFont (Font (15.00f, Font::plain));
    amplitudeLabel->setJustificationType (Justification::centred);
    amplitudeLabel->setEditable (false, false, false);
    amplitudeLabel->setColour (Label::textColourId, Colour (0xff00c7ed));
    amplitudeLabel->setColour (TextEditor::textColourId, Colours::black);
    amplitudeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (bypassButton = new ToggleButton ("Bypass Button"));
    bypassButton->setButtonText (TRANS("new toggle button"));
    bypassButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    getProcessor()->RequestUIUpdate();
    startTimer(50); //Start timer with interval in milliseconds.
    bypassButton->setClickingTogglesState(true);
    //[/Constructor]
}

StageDirectorAudioProcessorEditor::~StageDirectorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    titleLabel = nullptr;
    windowTypeSelector = nullptr;
    windowLabel = nullptr;
    fftSizeSldier = nullptr;
    sizeLabel = nullptr;
    hopSlider = nullptr;
    label = nullptr;
    centroidBox = nullptr;
    centroidLabel = nullptr;
    amplitudeBox = nullptr;
    amplitudeLabel = nullptr;
    bypassButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void StageDirectorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff373737));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StageDirectorAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    titleLabel->setBounds (40, 8, 352, 48);
    windowTypeSelector->setBounds (240, 80, 150, 24);
    windowLabel->setBounds (240, 112, 150, 24);
    fftSizeSldier->setBounds (48, 64, 176, 48);
    sizeLabel->setBounds (64, 112, 150, 24);
    hopSlider->setBounds (128, 136, 176, 48);
    label->setBounds (141, 184, 150, 24);
    centroidBox->setBounds (88, 232, 256, 56);
    centroidLabel->setBounds (144, 288, 150, 24);
    amplitudeBox->setBounds (88, 328, 256, 56);
    amplitudeLabel->setBounds (144, 384, 150, 24);
    bypassButton->setBounds (8, 424, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StageDirectorAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    StageDirectorAudioProcessor* ourProcessor = getProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == windowTypeSelector)
    {
        //[UserComboBoxCode_windowTypeSelector] -- add your combo box handling code here..
        ourProcessor->setParameter(StageDirectorAudioProcessor::kWindowType, (float)windowTypeSelector->getSelectedItemIndex());
        //[/UserComboBoxCode_windowTypeSelector]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void StageDirectorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    StageDirectorAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fftSizeSldier)
    {
        //[UserSliderCode_fftSizeSldier] -- add your slider handling code here..
        ourProcessor->setParameter(StageDirectorAudioProcessor::kFFTSize, fftSizeSldier->getValue());
        //[/UserSliderCode_fftSizeSldier]
    }
    else if (sliderThatWasMoved == hopSlider)
    {
        //[UserSliderCode_hopSlider] -- add your slider handling code here..
        ourProcessor->setParameter(StageDirectorAudioProcessor::kHopSize, hopSlider->getValue());
        //[/UserSliderCode_hopSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void StageDirectorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton)
    {
        //[UserButtonCode_bypassButton] -- add your button handler code here..
        //[/UserButtonCode_bypassButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void StageDirectorAudioProcessorEditor::timerCallback()
{
    StageDirectorAudioProcessor* ourProcessor = getProcessor();

    if(ourProcessor->NeedsUIUpdate())
    {
        bypassButton->setToggleState(1.0f == ourProcessor->getParameter(StageDirectorAudioProcessor::kMasterBypass), dontSendNotification);
        fftSizeSldier->setValue(ourProcessor->getParameter(StageDirectorAudioProcessor::kFFTSize), dontSendNotification);
        windowTypeSelector->setSelectedId(ourProcessor->getParameter(StageDirectorAudioProcessor::kWindowType), dontSendNotification);
        hopSlider->setValue(ourProcessor->getParameter(StageDirectorAudioProcessor::kHopSize), dontSendNotification);
        centroidBox->setText(String(ourProcessor->centroid_), dontSendNotification);
        amplitudeBox->setText(String(ourProcessor->level_), dontSendNotification);
        ourProcessor->ClearUIUpdateFlag();
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StageDirectorAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer, public SliderListener"
                 constructorParams="StageDirectorAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff373737"/>
  <LABEL name="Plugin Title" id="62e102d7da11b5d1" memberName="titleLabel"
         virtualName="" explicitFocusOrder="0" pos="40 8 352 48" bkgCol="ff4d4d4d"
         textCol="fb00c7ed" outlineCol="ff007c94" edTextCol="ff000000"
         edBkgCol="0" labelText="Stage Director" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Avenir"
         fontsize="53" bold="0" italic="0" justification="36"/>
  <COMBOBOX name="Window Function Selection" id="62c6cc0ff81acf2b" memberName="windowTypeSelector"
            virtualName="" explicitFocusOrder="0" pos="240 80 150 24" editable="0"
            layout="36" items="Rectangular&#10;Bartlett&#10;Hanning&#10;Hamming"
            textWhenNonSelected="Select" textWhenNoItems="(no choices)"/>
  <LABEL name="Window Label" id="498748351f67f37b" memberName="windowLabel"
         virtualName="" explicitFocusOrder="0" pos="240 112 150 24" textCol="ff00c7ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Window Function"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="FFT Size Slider" id="1d1d11c51ccd91f1" memberName="fftSizeSldier"
          virtualName="" explicitFocusOrder="0" pos="48 64 176 48" thumbcol="ff00c7ed"
          trackcol="8b00374f" textboxtext="ffffffff" textboxbkgd="ff4d4d4d"
          textboxhighlight="0" textboxoutline="ff377c94" min="0" max="16384"
          int="128" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="14" skewFactor="1"/>
  <LABEL name="FFT Size Label" id="6616f0ee28f280fa" memberName="sizeLabel"
         virtualName="" explicitFocusOrder="0" pos="64 112 150 24" textCol="ff00c7ed"
         edTextCol="ff000000" edBkgCol="0" labelText="FFT Size (samples)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="Hop Size Slider" id="ba8b9a989f65eaf8" memberName="hopSlider"
          virtualName="" explicitFocusOrder="0" pos="128 136 176 48" thumbcol="ff00c7ed"
          trackcol="8b00374f" textboxtext="ffffffff" textboxbkgd="ff4d4d4d"
          textboxoutline="ff007c94" min="0" max="8192" int="128" style="LinearHorizontal"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="14" skewFactor="1"/>
  <LABEL name="new label" id="cb99244442db3d5e" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="141 184 150 24" textCol="ff00c7ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Hop Size (samples)"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Centroid Value" id="937cc7b169e785d2" memberName="centroidBox"
         virtualName="" explicitFocusOrder="0" pos="88 232 256 56" bkgCol="ff4d4d4d"
         textCol="ff00c7ed" outlineCol="ff007c94" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="69.400000000000005684"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Centroid Label" id="88f9e310be03d4e1" memberName="centroidLabel"
         virtualName="" explicitFocusOrder="0" pos="144 288 150 24" textCol="ff00c7ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Spectral Centroid"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="Average Amplitude Value" id="144fbd42f15e7c09" memberName="amplitudeBox"
         virtualName="" explicitFocusOrder="0" pos="88 328 256 56" bkgCol="ff4d4d4d"
         textCol="ff00c7ed" outlineCol="ff007c94" edTextCol="ff000000"
         edBkgCol="0" labelText="0" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="69.400000000000005684"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Average Amplitude Label" id="8a3587ed788578d6" memberName="amplitudeLabel"
         virtualName="" explicitFocusOrder="0" pos="144 384 150 24" textCol="ff00c7ed"
         edTextCol="ff000000" edBkgCol="0" labelText="Amplitude Level"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="Bypass Button" id="a6bf3a00d0567e17" memberName="bypassButton"
                virtualName="" explicitFocusOrder="0" pos="8 424 150 24" buttonText="new toggle button"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
