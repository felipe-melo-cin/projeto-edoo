#ifndef _STATEMACHINE_H_
#define _STATEMACHINE_H_

class StateMachine { // CONTROLA OS ESTADOS DO JOGO

    private:

        StateMachine(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        // ESTADOS DO JOGO
        bool emJogo;
        bool venceu;

    public:

        // SINGLETON DESIGN PATTERN

        StateMachine(const StateMachine&) = delete;
        StateMachine& operator=(const StateMachine&) = delete;

        static StateMachine& get_instance();

        // END SINGLETON DESIGN PATTERN

        // RETORNA ESTADO DO JOGO
        bool get_em_jogo() const { return emJogo; }
        bool get_venceu() const { return venceu; }

        // INVERTE ESTADO DO JOGO
        void toggle_em_jogo() { emJogo = !emJogo; }
        void toggle_venceu() { venceu = !venceu; }

};

#endif