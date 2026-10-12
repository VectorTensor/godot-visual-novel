#pragma once

#include <godot_cpp/classes/node2d.hpp>
namespace godot {

    class dialogueText: public Node2D{
        GDCLASS(dialogueText, Node2D)

    private:
        double time_passed;
        double amplitude;

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