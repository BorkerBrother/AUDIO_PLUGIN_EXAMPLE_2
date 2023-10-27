//
// Created by Kai on 27.10.23.
//

#include <juce_audio_processors/juce_audio_processors.h>

namespace Gui {

class VerticalGradientMeter : public juce::Component, public juce::Timer {

    public:
        VerticalGradientMeter(std::function<float()>&& valueFunction) : valueSupplier(std::move(valueFunction))
        {
            startTimer(24);
        }


        void paint (juce::Graphics& g) override
        {
            const auto level = valueSupplier();
            auto bounds = getLocalBounds().toFloat();

            g.setColour(juce::Colours::white);
            g.fillRoundedRectangle(bounds,5);

            g.setGradientFill(gradient);
            const auto scaledY = juce::jmap(level,
                                            -60.f,
                                            +12.f,
                                            0.f,
                                            static_cast<float>(getHeight()));

            g.fillRect(bounds.removeFromBottom(scaledY));


        }

        void resized() override
        {
            const auto bounds = getLocalBounds().toFloat();

            gradient = juce::ColourGradient {
                    juce::Colours::darkblue, // Bottom
                    bounds.getBottomLeft(),
                    juce::Colours::chocolate,         // TOP
                    bounds.getTopLeft(),
                    false
            };
            gradient.addColour(0.f, juce::Colours::blueviolet);
        }

        void timerCallback()
        {
            repaint();
        }

    private:
        std::function<float()> valueSupplier;
        juce::ColourGradient gradient {};

    };

};