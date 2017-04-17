#pragma once
#include <stdint.h>
#include <stdlib.h>

template <class T>
class Board
{
protected:
	T* m_Board;
	uint32_t m_SideSize;

	inline uint32_t Get1DIndex(const uint32_t& i, const uint32_t& j) const { return m_SideSize * i + j; }
public:
	Board() :
		m_SideSize(0), m_Board(nullptr)
	{}

	Board(uint32_t sideSize) :
		m_SideSize(sideSize)
	{
		m_Board = (T*)malloc(m_SideSize * m_SideSize * sizeof(T));
	}

	Board(const Board& board)
	{
		Duplicate(board);
	}

   void Duplicate(const Board& original)
   {
		free(m_Board);
		m_SideSize = original.m_SideSize;
		m_Board = (T*)malloc(GetTotalSize() * sizeof(T));
		memcpy(m_Board, original.m_Board, GetTotalSize() * sizeof(T));
	}

	inline void SetElement(uint32_t i, uint32_t j, const T& value) { m_Board[Get1DIndex(i, j)] = value; }

	inline T& GetElement(uint32_t i, uint32_t j) { return m_Board[Get1DIndex(i, j)]; }
	inline T GetElement(uint32_t i, uint32_t j) const { return m_Board[Get1DIndex(i, j)]; }
	inline T& GetElement(uint32_t i) { return m_Board[i]; }
	inline T GetElement(uint32_t i) const { return m_Board[i]; }

	inline uint32_t GetSideSize() const { return m_SideSize; }
	inline uint32_t GetTotalSize() const { return m_SideSize * m_SideSize; }

	void operator= (const Board& original)
	{
		Duplicate(original);
	}

	T& operator[](uint32_t i)
	{
		return m_Board[i];
	}

	~Board()
	{
		delete[] m_Board;
	}

	void Print() const
	{
		for (uint32_t i = 0; i < m_SideSize; ++i)
		{
			for (uint32_t j = 0; j < m_SideSize; j++)
			{
				std::cout << m_Board[i * m_SideSize + j] << " ";
			}
			std::cout << std::endl;
		}
	}

};