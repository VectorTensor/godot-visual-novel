#pragma once

#include <godot_cpp/classes/node2d.hpp>

#include "godot_cpp/classes/label.hpp"

namespace godot {

    class dialogueText: public Node2D{
        GDCLASS(dialogueText, Node2D)

    private:
        Label* label;
        String sampleText;
        int64_t max_length = 20;
        int current_length = 0;
        double current_delta = 0;
        double speed = 0.01;

    protected:
        static void _bind_methods();

    public:
        dialogueText();
        ~dialogueText();
        void set_dialogue_box(Label *node);

        Label *get_dialogue_box() const;

        void _process(double delta) override;
        void _ready() override;
    };

} // namespace godot