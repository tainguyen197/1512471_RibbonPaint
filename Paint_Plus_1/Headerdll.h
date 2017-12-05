namespace libdll
{ 
	class myclass{
	public:
		static __declspec(dllexport) bool Open();
		static __declspec(dllexport) bool Save();
	};
}