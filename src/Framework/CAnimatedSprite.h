#ifndef CANIMATEDSPRITE_H_
#define CANIMATEDSPRITE_H_
#include "CAssetsManager.h"
#include "CSprite.h"

/** \brief Classe para sprites com animação.
*
* 
*/
class CAnimatedSprite: public CSprite
{
public:
	/** \brief Construtor para a  classe.
	*
	*\param img Ponteiro para SDL_Surface de onde os quadros da animação serão extraidos.
	*\param frameX Largura de cada quadro.
	*\param frameY Altura de cada quado.
	*\param fps Velocidade para troca de quadros(quadros por segundo).
	*/
	CAnimatedSprite(SDL_Surface* img, int frameX, int frameY, float fps);
	

	/**\brief Destrutor para a classe.
	*/
	~CAnimatedSprite();

	/** \brief Método que desenha o quadro atual da animação na tela.
	*/
	void draw();


	/** \brief Método que troca os quadros da animação de acordo com o tempo decorrido.
	* \param dt Tempo decorrido desde a última renderização.
	*
	* O método update de cada CAnimatedSprite deve ser chamado no método update
	* do CGameState que o contém, sem a chamada ao método, o quadro da animação
	* nunca será trocado.
	*/
	void update( Uint32 dt );
private:
	SDL_Rect* clips;
	int framesCount;
	int currFrame;
	float fps;
	Uint32 elapsedTime;
};

#endif /* CANIMATEDSPRITE_H_ */
