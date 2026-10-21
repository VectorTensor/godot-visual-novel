#pragma once

#include <godot_cpp/classes/node2d.hpp>

#include "godot_cpp/classes/label.hpp"

namespace godot {

    class dialogueText: public Node2D{
        GDCLASS(dialogueText, Node2D)

    private:
        godot::Label* label;

    protected:
        static void _bind_methods();

    public:
        void set_amplitude(const double p_amplitude);
        double get_amplitude() const;
        dialogueText();
        ~dialogueText();

        void _process(double delta) override;
    };

} // namespace godot