
#ifndef DIALOGUE_TEXT_HPP
#define DIALOGUE_TEXT_HPP

#include <godot_cpp/classes/node2d.hpp>

#include "godot_cpp/classes/label.hpp"

namespace godot {

    class dialogueText: public Node2D{
        GDCLASS(dialogueText, Node2D)

        Label* label;
        String sampleText;
        int64_t max_length = 20;
        int current_length = 0;
        double current_delta = 0;
        double speed = 0.01;
        String yaml_path = "res://assets/dialogues/test_dialogue.yaml";

    protected:
        static void _bind_methods();

    public:
        dialogueText();
        ~dialogueText();
        void set_dialogue_box(Label *node);

        Label *get_dialogue_box() const;

        void _process(double delta) override;
        void _ready() override;
        void set_yaml_path(const String &path);
        String get_yaml_path() const;

        void load_dialogue();
    };

} // namespace godot

#endif