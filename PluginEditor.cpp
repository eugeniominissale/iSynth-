/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ISynthPluginAudioProcessorEditor::ISynthPluginAudioProcessorEditor (ISynthPluginAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (100, 9000, 1);
    slider->setSliderStyle (Slider::Rotary);
    slider->setTextBoxStyle (Slider::TextBoxAbove, false, 60, 20);
    slider->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    slider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f4646e4));
    slider->addListener (this);

    addAndMakeVisible (slider1 = new Slider ("new slider"));
    slider1->setRange (100, 9000, 1);
    slider1->setSliderStyle (Slider::Rotary);
    slider1->setTextBoxStyle (Slider::TextBoxAbove, false, 60, 20);
    slider1->addListener (this);

    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("ON/OFF"));
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("SINE"));
    comboBox->setTextWhenNoChoicesAvailable (String::empty);
    comboBox->addItem (TRANS("SINE"), 1);
    comboBox->addItem (TRANS("SAW"), 2);
    comboBox->addItem (TRANS("SQUARE"), 3);
    comboBox->addItem (TRANS("TRIANGLE"), 4);
    comboBox->addListener (this);

    addAndMakeVisible (textButton1 = new TextButton ("new button1"));
    textButton1->setButtonText (TRANS("ON/OFF"));
    textButton1->addListener (this);
    textButton1->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (comboBox1 = new ComboBox ("new combo box1"));
    comboBox1->setEditableText (false);
    comboBox1->setJustificationType (Justification::centredLeft);
    comboBox1->setTextWhenNothingSelected (TRANS("SINE"));
    comboBox1->setTextWhenNoChoicesAvailable (String::empty);
    comboBox1->addItem (TRANS("SINE"), 1);
    comboBox1->addItem (TRANS("SAW"), 2);
    comboBox1->addItem (TRANS("SQUARE"), 3);
    comboBox1->addItem (TRANS("TRIANGLE"), 4);
    comboBox1->addListener (this);

    addAndMakeVisible (sliderA = new Slider ("new slider"));
    sliderA->setRange (0, 5, 0.01);
    sliderA->setSliderStyle (Slider::LinearVertical);
    sliderA->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sliderA->addListener (this);

    addAndMakeVisible (sliderD = new Slider ("new slider"));
    sliderD->setRange (0.01, 5, 0.01);
    sliderD->setSliderStyle (Slider::LinearVertical);
    sliderD->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sliderD->addListener (this);

    addAndMakeVisible (sliderS = new Slider ("new slider"));
    sliderS->setRange (0, 5, 0.01);
    sliderS->setSliderStyle (Slider::LinearVertical);
    sliderS->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sliderS->addListener (this);

    addAndMakeVisible (sliderR = new Slider ("new slider"));
    sliderR->setRange (0, 5, 0.01);
    sliderR->setSliderStyle (Slider::LinearVertical);
    sliderR->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    sliderR->addListener (this);

    addAndMakeVisible (sliderCO = new Slider ("new slider"));
    sliderCO->setRange (0, 1, 0.01);
    sliderCO->setSliderStyle (Slider::Rotary);
    sliderCO->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderCO->addListener (this);

    addAndMakeVisible (textButtonF = new TextButton ("new button1"));
    textButtonF->setButtonText (TRANS("ON/OFF"));
    textButtonF->addListener (this);
    textButtonF->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (sliderRES = new Slider ("new slider"));
    sliderRES->setRange (0, 1, 0.01);
    sliderRES->setSliderStyle (Slider::Rotary);
    sliderRES->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    sliderRES->addListener (this);

    addAndMakeVisible (comboBoxF = new ComboBox ("new combo box"));
    comboBoxF->setEditableText (false);
    comboBoxF->setJustificationType (Justification::centredLeft);
    comboBoxF->setTextWhenNothingSelected (TRANS("LP"));
    comboBoxF->setTextWhenNoChoicesAvailable (TRANS("LP"));
    comboBoxF->addItem (TRANS("LP"), 1);
    comboBoxF->addItem (TRANS("HP"), 2);
    comboBoxF->addItem (TRANS("BP"), 3);
    comboBoxF->addSeparator();
    comboBoxF->addSeparator();
    comboBoxF->addListener (this);

    addAndMakeVisible (textEditor = new TextEditor ("new text editor"));
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (TRANS("RES"));

    addAndMakeVisible (textEditor2 = new TextEditor ("new text editor"));
    textEditor2->setMultiLine (false);
    textEditor2->setReturnKeyStartsNewLine (false);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (true);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setText (TRANS("COF"));

    addAndMakeVisible (textButtonE = new TextButton ("new button"));
    textButtonE->setButtonText (TRANS("ON/OFF"));
    textButtonE->addListener (this);
    textButtonE->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (sliderLFO = new Slider ("new slider"));
    sliderLFO->setRange (0, 10, 0);
    sliderLFO->setSliderStyle (Slider::Rotary);
    sliderLFO->setTextBoxStyle (Slider::TextBoxAbove, false, 60, 20);
    sliderLFO->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    sliderLFO->addListener (this);

    addAndMakeVisible (sliderLFOMA = new Slider ("new slider"));
    sliderLFOMA->setRange (0, 1, 0);
    sliderLFOMA->setSliderStyle (Slider::Rotary);
    sliderLFOMA->setTextBoxStyle (Slider::TextBoxAbove, false, 60, 20);
    sliderLFOMA->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    sliderLFOMA->addListener (this);

    addAndMakeVisible (component2 = new MIDIContentComponent());
    addAndMakeVisible (textEditor3 = new TextEditor ("new text editor"));
    textEditor3->setMultiLine (false);
    textEditor3->setReturnKeyStartsNewLine (false);
    textEditor3->setReadOnly (false);
    textEditor3->setScrollbarsShown (true);
    textEditor3->setCaretVisible (true);
    textEditor3->setPopupMenuEnabled (true);
    textEditor3->setText (TRANS("MOD AMOUNT"));

    addAndMakeVisible (comboBoxL = new ComboBox ("new combo box1"));
    comboBoxL->setEditableText (false);
    comboBoxL->setJustificationType (Justification::centredLeft);
    comboBoxL->setTextWhenNothingSelected (TRANS("SINE"));
    comboBoxL->setTextWhenNoChoicesAvailable (String::empty);
    comboBoxL->addItem (TRANS("SINE"), 1);
    comboBoxL->addItem (TRANS("SAW"), 2);
    comboBoxL->addItem (TRANS("SQUARE"), 3);
    comboBoxL->addItem (TRANS("TRIANGLE"), 4);
    comboBoxL->addListener (this);

    addAndMakeVisible (comboBoxLM = new ComboBox ("new combo box"));
    comboBoxLM->setEditableText (false);
    comboBoxLM->setJustificationType (Justification::centredLeft);
    comboBoxLM->setTextWhenNothingSelected (TRANS("FILTER"));
    comboBoxLM->setTextWhenNoChoicesAvailable (TRANS("FILTER"));
    comboBoxLM->addItem (TRANS("FILTER"), 1);
    comboBoxLM->addItem (TRANS("PITCH"), 2);
    comboBoxLM->addListener (this);

    addAndMakeVisible (textButtonE2 = new TextButton ("new button"));
    textButtonE2->setButtonText (TRANS("ON/OFF"));
    textButtonE2->addListener (this);
    textButtonE2->setColour (TextButton::buttonColourId, Colours::white);

    addAndMakeVisible (comboBoxSeq = new ComboBox ("new combo box"));
    comboBoxSeq->setEditableText (false);
    comboBoxSeq->setJustificationType (Justification::centredLeft);
    comboBoxSeq->setTextWhenNothingSelected (TRANS("OFF"));
    comboBoxSeq->setTextWhenNoChoicesAvailable (TRANS("OFF"));
    comboBoxSeq->addItem (TRANS("OFF"), 1);
    comboBoxSeq->addItem (TRANS("PLAY"), 2);
    comboBoxSeq->addItem (TRANS("RECORD"), 3);
    comboBoxSeq->addListener (this);

    addAndMakeVisible (textEditor4 = new TextEditor ("new text editor"));
    textEditor4->setMultiLine (false);
    textEditor4->setReturnKeyStartsNewLine (false);
    textEditor4->setReadOnly (false);
    textEditor4->setScrollbarsShown (true);
    textEditor4->setCaretVisible (true);
    textEditor4->setPopupMenuEnabled (true);
    textEditor4->setText (TRANS("SEQUENCER"));

    addAndMakeVisible (sliderSeq = new Slider ("new slider"));
    sliderSeq->setRange (1, 180, 1);
    sliderSeq->setSliderStyle (Slider::Rotary);
    sliderSeq->setTextBoxStyle (Slider::TextBoxAbove, false, 60, 20);
    sliderSeq->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    sliderSeq->addListener (this);

    addAndMakeVisible (textEditor5 = new TextEditor ("new text editor"));
    textEditor5->setMultiLine (false);
    textEditor5->setReturnKeyStartsNewLine (false);
    textEditor5->setReadOnly (false);
    textEditor5->setScrollbarsShown (true);
    textEditor5->setCaretVisible (true);
    textEditor5->setPopupMenuEnabled (true);
    textEditor5->setText (TRANS("BMP"));

    addAndMakeVisible (textEditor6 = new TextEditor ("new text editor"));
    textEditor6->setMultiLine (false);
    textEditor6->setReturnKeyStartsNewLine (false);
    textEditor6->setReadOnly (false);
    textEditor6->setScrollbarsShown (true);
    textEditor6->setCaretVisible (true);
    textEditor6->setPopupMenuEnabled (true);
    textEditor6->setText (TRANS("FREQ"));

    addAndMakeVisible (textEditor7 = new TextEditor ("new text editor"));
    textEditor7->setMultiLine (false);
    textEditor7->setReturnKeyStartsNewLine (false);
    textEditor7->setReadOnly (false);
    textEditor7->setScrollbarsShown (true);
    textEditor7->setCaretVisible (true);
    textEditor7->setPopupMenuEnabled (true);
    textEditor7->setText (TRANS("ENVELOPE"));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    textButton->setClickingTogglesState(true);
    textButton1->setClickingTogglesState(true);
    textButtonF->setClickingTogglesState(true);
    textButtonE->setClickingTogglesState(true);
    textButtonE2->setClickingTogglesState(true);


    //[/Constructor]
}

ISynthPluginAudioProcessorEditor::~ISynthPluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    slider1 = nullptr;
    textButton = nullptr;
    comboBox = nullptr;
    textButton1 = nullptr;
    comboBox1 = nullptr;
    sliderA = nullptr;
    sliderD = nullptr;
    sliderS = nullptr;
    sliderR = nullptr;
    sliderCO = nullptr;
    textButtonF = nullptr;
    sliderRES = nullptr;
    comboBoxF = nullptr;
    textEditor = nullptr;
    textEditor2 = nullptr;
    textButtonE = nullptr;
    sliderLFO = nullptr;
    sliderLFOMA = nullptr;
    component2 = nullptr;
    textEditor3 = nullptr;
    comboBoxL = nullptr;
    comboBoxLM = nullptr;
    textButtonE2 = nullptr;
    comboBoxSeq = nullptr;
    textEditor4 = nullptr;
    sliderSeq = nullptr;
    textEditor5 = nullptr;
    textEditor6 = nullptr;
    textEditor7 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ISynthPluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ISynthPluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (8, 32, 72, 64);
    slider1->setBounds (168, 32, 64, 64);
    textButton->setBounds (80, 64, 80, 24);
    comboBox->setBounds (80, 32, 80, 24);
    textButton1->setBounds (232, 64, 80, 24);
    comboBox1->setBounds (232, 32, 80, 24);
    sliderA->setBounds (56, 128, 64, 80);
    sliderD->setBounds (104, 128, 64, 80);
    sliderS->setBounds (152, 128, 64, 80);
    sliderR->setBounds (200, 128, 64, 80);
    sliderCO->setBounds (392, 32, 64, 64);
    textButtonF->setBounds (464, 64, 80, 24);
    sliderRES->setBounds (320, 32, 64, 64);
    comboBoxF->setBounds (464, 32, 80, 24);
    textEditor->setBounds (336, 8, 31, 24);
    textEditor2->setBounds (408, 8, 32, 24);
    textButtonE->setBounds (464, 136, 80, 24);
    sliderLFO->setBounds (368, 104, 112, 64);
    sliderLFOMA->setBounds (296, 104, 112, 64);
    component2->setBounds (56, 256, 216, 128);
    textEditor3->setBounds (304, 168, 96, 24);
    comboBoxL->setBounds (464, 104, 80, 24);
    comboBoxLM->setBounds (464, 168, 80, 24);
    textButtonE2->setBounds (128, 216, 80, 24);
    comboBoxSeq->setBounds (464, 200, 80, 24);
    textEditor4->setBounds (464, 232, 80, 24);
    sliderSeq->setBounds (376, 200, 64, 64);
    textEditor5->setBounds (392, 264, 32, 24);
    textEditor6->setBounds (408, 168, 40, 24);
    textEditor7->setBounds (128, 104, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ISynthPluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    ISynthPluginAudioProcessor* ourProcessor=getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::SliderOsc,(float)slider->getValue());
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == slider1)
    {
        //[UserSliderCode_slider1] -- add your slider handling code here..
          ourProcessor->setParameter(ISynthPluginAudioProcessor::SliderOsc1,(float)slider1->getValue());
        //[/UserSliderCode_slider1]
    }
    else if (sliderThatWasMoved == sliderA)
    {
        //[UserSliderCode_sliderA] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::envA,(float)sliderA->getValue());
        //[/UserSliderCode_sliderA]
    }
    else if (sliderThatWasMoved == sliderD)
    {
        //[UserSliderCode_sliderD] -- add your slider handling code here..
         ourProcessor->setParameter(ISynthPluginAudioProcessor::envD,(float)sliderD->getValue());
        //[/UserSliderCode_sliderD]
    }
    else if (sliderThatWasMoved == sliderS)
    {
        //[UserSliderCode_sliderS] -- add your slider handling code here..
         ourProcessor->setParameter(ISynthPluginAudioProcessor::envS,(float)sliderS->getValue());
        //[/UserSliderCode_sliderS]
    }
    else if (sliderThatWasMoved == sliderR)
    {
        //[UserSliderCode_sliderR] -- add your slider handling code here..
         ourProcessor->setParameter(ISynthPluginAudioProcessor::envR,(float)sliderR->getValue());
        //[/UserSliderCode_sliderR]
    }
    else if (sliderThatWasMoved == sliderCO)
    {
        //[UserSliderCode_sliderCO] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::cof,(float)sliderCO->getValue());
        //[/UserSliderCode_sliderCO]
    }
    else if (sliderThatWasMoved == sliderRES)
    {
        //[UserSliderCode_sliderRES] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::res,(float)sliderRES->getValue());
        //[/UserSliderCode_sliderRES]
    }
    else if (sliderThatWasMoved == sliderLFO)
    {
        //[UserSliderCode_sliderLFO] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::lfoFreq,(float)sliderLFO->getValue());
        //[/UserSliderCode_sliderLFO]
    }
    else if (sliderThatWasMoved == sliderLFOMA)
    {
        //[UserSliderCode_sliderLFOMA] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::lfoFilterModAmount,(float)sliderLFOMA->getValue());
        //[/UserSliderCode_sliderLFOMA]
    }
    else if (sliderThatWasMoved == sliderSeq)
    {
        //[UserSliderCode_sliderSeq] -- add your slider handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::sliderSeq,(float)sliderSeq->getValue());
        //[/UserSliderCode_sliderSeq]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void ISynthPluginAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    ISynthPluginAudioProcessor* ourProcessor=getProcessor();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::ByPass,(float)textButton->getToggleState());
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton1)
    {
        //[UserButtonCode_textButton1] -- add your button handler code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::ByPass1,(float)textButton1->getToggleState());
        //[/UserButtonCode_textButton1]
    }
    else if (buttonThatWasClicked == textButtonF)
    {
        //[UserButtonCode_textButtonF] -- add your button handler code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::ByPass2,(float)textButtonF->getToggleState());
        //[/UserButtonCode_textButtonF]
    }
    else if (buttonThatWasClicked == textButtonE)
    {
        //[UserButtonCode_textButtonE] -- add your button handler code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::ByPass3,(float)textButtonE->getToggleState());
        //[/UserButtonCode_textButtonE]
    }
    else if (buttonThatWasClicked == textButtonE2)
    {
        //[UserButtonCode_textButtonE2] -- add your button handler code here..
         ourProcessor->setParameter(ISynthPluginAudioProcessor::ByPass4,(float)textButtonE2->getToggleState());
        //[/UserButtonCode_textButtonE2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void ISynthPluginAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    ISynthPluginAudioProcessor* ourProcessor=getProcessor();
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::oscMode,(int)comboBox->getSelectedId());
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == comboBox1)
    {
        //[UserComboBoxCode_comboBox1] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::oscMode1,(int)comboBox1->getSelectedId());
        //[/UserComboBoxCode_comboBox1]
    }
    else if (comboBoxThatHasChanged == comboBoxF)
    {
        //[UserComboBoxCode_comboBoxF] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::filMode,(int)comboBoxF->getSelectedId());
        //[/UserComboBoxCode_comboBoxF]
    }
    else if (comboBoxThatHasChanged == comboBoxL)
    {
        //[UserComboBoxCode_comboBoxL] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::lfoMode,(int)comboBoxL->getSelectedId());
        //[/UserComboBoxCode_comboBoxL]
    }
    else if (comboBoxThatHasChanged == comboBoxLM)
    {
        //[UserComboBoxCode_comboBoxLM] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::lfoMode2,(int)comboBoxLM->getSelectedId());
        //[/UserComboBoxCode_comboBoxLM]
    }
    else if (comboBoxThatHasChanged == comboBoxSeq)
    {
        //[UserComboBoxCode_comboBoxSeq] -- add your combo box handling code here..
        ourProcessor->setParameter(ISynthPluginAudioProcessor::seqMode,(int)comboBoxSeq->getSelectedId());
        //[/UserComboBoxCode_comboBoxSeq]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

/*callback=struttura dati che ci dice quali parametri sono cambiati e a quale frame - routine di callback chiamata periodicamente*/

void ISynthPluginAudioProcessorEditor::timerCallback()
{
    ISynthPluginAudioProcessor* ourProcessor=getProcessor();
    slider->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::SliderOsc),dontSendNotification);
    textButton->setToggleState(ourProcessor->getParameter(ISynthPluginAudioProcessor::ByPass),dontSendNotification);
    comboBox->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::oscMode));
    /*-----------------------------------------------------------------------------------------*/
    slider1->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::SliderOsc1),dontSendNotification);
    textButton1->setToggleState(ourProcessor->getParameter(ISynthPluginAudioProcessor::ByPass1),dontSendNotification);
    comboBox1->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::oscMode1));
    /*-----------------------------------------------------------------------------------------*/
    sliderA->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::envA), dontSendNotification);
    sliderD->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::envD), dontSendNotification);
    sliderS->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::envS), dontSendNotification);
    sliderR->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::envR), dontSendNotification);
    textButtonE2->setToggleState(ourProcessor->getParameter(ISynthPluginAudioProcessor::ByPass4),dontSendNotification);
    /*FILTRO-------------------------------------------------------------------------------------*/
    sliderCO->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::cof), dontSendNotification);
    sliderRES->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::res), dontSendNotification);
    textButtonF->setToggleState(1.0f==ourProcessor->getParameter(ISynthPluginAudioProcessor::ByPass2),dontSendNotification);
    comboBoxF->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::filMode),dontSendNotification);
    /*LFO-------------------------------------------------------------------------------------*/
    sliderLFO->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::lfoFreq), dontSendNotification);
    sliderLFOMA->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::lfoFilterModAmount), dontSendNotification);
    comboBox->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::lfoMode));
    comboBox->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::lfoMode2));
    /*SEQ------------------------------------------------------------------------------------------------------------------------*/
    comboBoxSeq->setSelectedId(ourProcessor->getParameter(ISynthPluginAudioProcessor::seqMode), dontSendNotification);
    sliderSeq->setValue(ourProcessor->getParameter(ISynthPluginAudioProcessor::sliderSeq), dontSendNotification);

    ourProcessor->ClearUIUpdateFlag(); //per i prossimi spostmaenti(altri slider)..
}





/*------OSCILLOSCOPIO----*/

MyOpenGLCanvas::MyOpenGLCanvas(){

    startTimer (200);  // redraw every 200ms

}
MyOpenGLCanvas::~MyOpenGLCanvas(){

}

void MyOpenGLCanvas::renderOpenGL(){

    glClearColor (0.0,0.0,0.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslated(-1.0, 0.0, 0.0);

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP); //begin the four sided shape

    for (int i = 0; i < 64; i++){
        glVertex3f(i/(64/2.),sin(i), 0);
    }

    glEnd(); //end the shape we are currently working on

    glFlush();

}

void MyOpenGLCanvas::newOpenGLContextCreated(){


}

void MyOpenGLCanvas::timerCallback(){

    repaint();
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ISynthPluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="ISynthPluginAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="6a605b2b34b47fee" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="8 32 72 64" bkgcol="ffffff" rotarysliderfill="7f4646e4"
          min="100" max="9000" int="1" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="adb831130637ecad" memberName="slider1"
          virtualName="" explicitFocusOrder="0" pos="168 32 64 64" min="100"
          max="9000" int="1" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button" id="33627eee975e3c2" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="80 64 80 24" bgColOff="ffffffff"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="bd3fe2e2c6e5614" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="80 32 80 24" editable="0"
            layout="33" items="SINE&#10;SAW&#10;SQUARE&#10;TRIANGLE" textWhenNonSelected="SINE"
            textWhenNoItems=""/>
  <TEXTBUTTON name="new button1" id="bcf68f2da5266590" memberName="textButton1"
              virtualName="" explicitFocusOrder="0" pos="232 64 80 24" bgColOff="ffffffff"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box1" id="d994846410775780" memberName="comboBox1"
            virtualName="" explicitFocusOrder="0" pos="232 32 80 24" editable="0"
            layout="33" items="SINE&#10;SAW&#10;SQUARE&#10;TRIANGLE" textWhenNonSelected="SINE"
            textWhenNoItems=""/>
  <SLIDER name="new slider" id="859d71b13c97e798" memberName="sliderA"
          virtualName="" explicitFocusOrder="0" pos="56 128 64 80" min="0"
          max="5" int="0.010000000000000000208" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="5c5e95bec733cffb" memberName="sliderD"
          virtualName="" explicitFocusOrder="0" pos="104 128 64 80" min="0.010000000000000000208"
          max="5" int="0.010000000000000000208" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="4bad7db20bed2954" memberName="sliderS"
          virtualName="" explicitFocusOrder="0" pos="152 128 64 80" min="0"
          max="5" int="0.010000000000000000208" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e870e031e53d7435" memberName="sliderR"
          virtualName="" explicitFocusOrder="0" pos="200 128 64 80" min="0"
          max="5" int="0.010000000000000000208" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="72d5b9d3789e3dc0" memberName="sliderCO"
          virtualName="" explicitFocusOrder="0" pos="392 32 64 64" min="0"
          max="1" int="0.010000000000000000208" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="new button1" id="f7d9bad1b2c314c9" memberName="textButtonF"
              virtualName="" explicitFocusOrder="0" pos="464 64 80 24" bgColOff="ffffffff"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="99a9a1dc548057fc" memberName="sliderRES"
          virtualName="" explicitFocusOrder="0" pos="320 32 64 64" min="0"
          max="1" int="0.010000000000000000208" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="new combo box" id="996ef83e7f2c83f" memberName="comboBoxF"
            virtualName="" explicitFocusOrder="0" pos="464 32 80 24" editable="0"
            layout="33" items="LP&#10;HP&#10;BP&#10;&#10;" textWhenNonSelected="LP"
            textWhenNoItems="LP"/>
  <TEXTEDITOR name="new text editor" id="3edd88c0dd52c089" memberName="textEditor"
              virtualName="" explicitFocusOrder="0" pos="336 8 31 24" initialText="RES"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="960372815decc2f0" memberName="textEditor2"
              virtualName="" explicitFocusOrder="0" pos="408 8 32 24" initialText="COF"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTBUTTON name="new button" id="995af3ea3c03139d" memberName="textButtonE"
              virtualName="" explicitFocusOrder="0" pos="464 136 80 24" bgColOff="ffffffff"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="e6372d933bfa43e3" memberName="sliderLFO"
          virtualName="" explicitFocusOrder="0" pos="368 104 112 64" bkgcol="ffffff"
          min="0" max="10" int="0" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="e411dce7150c183a" memberName="sliderLFOMA"
          virtualName="" explicitFocusOrder="0" pos="296 104 112 64" bkgcol="ffffff"
          min="0" max="1" int="0" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <JUCERCOMP name="" id="8163a26e7e566e0f" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="56 256 216 128" sourceFile="MIDIContentComponent.cpp"
             constructorParams=""/>
  <TEXTEDITOR name="new text editor" id="fd8997d1e4122de9" memberName="textEditor3"
              virtualName="" explicitFocusOrder="0" pos="304 168 96 24" initialText="MOD AMOUNT"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <COMBOBOX name="new combo box1" id="2f6cec402b5bf53a" memberName="comboBoxL"
            virtualName="" explicitFocusOrder="0" pos="464 104 80 24" editable="0"
            layout="33" items="SINE&#10;SAW&#10;SQUARE&#10;TRIANGLE" textWhenNonSelected="SINE"
            textWhenNoItems=""/>
  <COMBOBOX name="new combo box" id="d44112cb9bb5226f" memberName="comboBoxLM"
            virtualName="" explicitFocusOrder="0" pos="464 168 80 24" editable="0"
            layout="33" items="FILTER&#10;PITCH" textWhenNonSelected="FILTER"
            textWhenNoItems="FILTER"/>
  <TEXTBUTTON name="new button" id="7f224e65415c9cc" memberName="textButtonE2"
              virtualName="" explicitFocusOrder="0" pos="128 216 80 24" bgColOff="ffffffff"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <COMBOBOX name="new combo box" id="78528cd930341838" memberName="comboBoxSeq"
            virtualName="" explicitFocusOrder="0" pos="464 200 80 24" editable="0"
            layout="33" items="OFF&#10;PLAY&#10;RECORD" textWhenNonSelected="OFF"
            textWhenNoItems="OFF"/>
  <TEXTEDITOR name="new text editor" id="487c079459b2570e" memberName="textEditor4"
              virtualName="" explicitFocusOrder="0" pos="464 232 80 24" initialText="SEQUENCER"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <SLIDER name="new slider" id="416244aa28c6be56" memberName="sliderSeq"
          virtualName="" explicitFocusOrder="0" pos="376 200 64 64" bkgcol="ffffff"
          min="1" max="180" int="1" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="60" textBoxHeight="20" skewFactor="1"/>
  <TEXTEDITOR name="new text editor" id="85309151d5710f0f" memberName="textEditor5"
              virtualName="" explicitFocusOrder="0" pos="392 264 32 24" initialText="BMP"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="55eb09b6d5410eca" memberName="textEditor6"
              virtualName="" explicitFocusOrder="0" pos="408 168 40 24" initialText="FREQ"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TEXTEDITOR name="new text editor" id="11085ae81eb95f5d" memberName="textEditor7"
              virtualName="" explicitFocusOrder="0" pos="128 104 80 24" initialText="ENVELOPE"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
