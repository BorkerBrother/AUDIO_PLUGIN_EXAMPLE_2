//
// Created by Kai on 27.10.23.
//

#include <juce_audio_processors/juce_audio_processors.h>

namespace Gui {

class VerticalGradientMeter : public juce::Component {

    public:
        VerticalGradientMeter() {};


        void paint (juce::Graphics& g) override
        {
            const auto bounds = getLocalBounds().toFloat();
            g.setColour(juce::Colours::white);
            g.fillRoundedRectangle(bounds,5);

        }


    private:


    };

};