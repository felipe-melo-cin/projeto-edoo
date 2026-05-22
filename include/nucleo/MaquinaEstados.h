#ifndef _MAQUINAESTADOS_H_
#define _MAQUINAESTADOS_H_

// CONTROLA OS ESTADOS DO JOGO
class MaquinaEstados {

    private:

        MaquinaEstados(); // SINGLETON DESIGN PATTERN: CONSTRUTOR PRIVADO

        // ESTADOS DO JOGO
        
        bool emJogo;
        bool venceu;

    public:

        // SINGLETON DESIGN PATTERN

        MaquinaEstados(const MaquinaEstados&) = delete;
        MaquinaEstados& operator=(const MaquinaEstados&) = delete;

        static MaquinaEstados& get_instance();

        // END SINGLETON DESIGN PATTERN

        // RETORNA ESTADO DO JOGO

        bool get_em_jogo() const {return emJogo;}
        bool get_venceu () const {return venceu;}

        // INVERTE ESTADO DO JOGO

        void toggle_em_jogo() {emJogo = !emJogo;}
        void toggle_venceu () {venceu = !venceu;}

};

#endif