#pragma once

#include "PluginProcessor.h"
#include "Component/HorizontalMeter.h"
#include "Component/VerticalGradientMeter.h"



//==============================================================================
class AudioPluginAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Timer
{
public:
    explicit AudioPluginAudioProcessorEditor (AudioPluginAudioProcessor&);
    ~AudioPluginAudioProcessorEditor() override;

    //==============================================================================
    void timerCallback();
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginAudioProcessor& processorRef;

    Gui::HorizontalMeter horizontalMeterL, horizontalMeterR;

    Gui::VerticalGradientMeter verticalGradientMeterL, verticalGradientMeterR;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginAudioProcessorEditor)
};
