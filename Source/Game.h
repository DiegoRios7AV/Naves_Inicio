
class CGame
{
public:
	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado{
		estado_Iniciando,
		estado_Menu,
		estado_Jugando,
		estado_Terminado,
		estado_Finalizado
	};

private:
	Estado estado;
};