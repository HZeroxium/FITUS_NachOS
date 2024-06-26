#include "stable.h"

//************************************************************************************
//***************************** CONSTRUCTOR AND DESTRUCTOR ***************************
//************************************************************************************

/// @brief Default constructor
STable::STable()
{
    this->bm = new BitMap(MAX_SEMAPHORE);
    for (int i = 0; i < MAX_SEMAPHORE; i++)
    {
        this->semTab[i] = NULL;
    }
}

/// @brief Destructor
STable::~STable()
{
    if (this->bm)
    {
        delete this->bm;
        this->bm = NULL;
    }
    for (int i = 0; i < MAX_SEMAPHORE; i++)
    {
        if (this->semTab[i])
        {
            delete this->semTab[i];
            this->semTab[i] = NULL;
        }
    }
}

//************************************************************************************
//************************************ METHODS ***************************************
//************************************************************************************

/// @brief Create a new semaphore in semaphores table
/// @param name Name of semaphore
/// @param init Initial value of semaphore
/// @return 0 if success, -1 if fail
int STable::Create(char *name, int init)
{
    // Check if semaphore already exists
    for (int i = 0; i < MAX_SEMAPHORE; i++)
    {
        if (bm->Test(i))
        {
            if (strcmp(name, semTab[i]->GetName()) == 0)
            {
                return -1;
            }
        }
    }
    // Find free slot in semTab
    int id = this->FindFreeSlot();

    // If not found, return -1
    if (id < 0)
    {
        return -1;
    }

    // If found, create new semaphore in semTab[id]
    this->semTab[id] = new Sem(name, init);
    return 0;
}

/// @brief Down operation on semaphore with name
/// @param name Name of semaphore
/// @return 0 if success, -1 if fail
int STable::Wait(char *name)
{
    Sem *sem = GetSemaphore(name);
    if (sem == NULL)
    {
        return -1;
        printf("Semaphore not found\n");
    }
    sem->Wait();
    return 0;
}

/// @brief Up operation on semaphore with name
/// @param name Name of semaphore
/// @return 0 if success, -1 if fail
int STable::Signal(char *name)
{
    Sem *sem = GetSemaphore(name);
    if (sem == NULL)
    {
        return -1;
        printf("Semaphore not found\n");
    }
    sem->Signal();
    return 0;
}

/// @brief Get semaphore with name
/// @param name Name of semaphore
/// @return Pointer to semaphore if found, NULL if not found
Sem *STable::GetSemaphore(char *name)
{
    for (int i = 0; i < MAX_SEMAPHORE; i++)
    {
        if (bm->Test(i))
        {
            if (strcmp(name, semTab[i]->GetName()) == 0)
            {
                return semTab[i];
            }
        }
    }
    return NULL;
}

/// @brief Find free slot in semTab
/// @return Index of free slot if found, -1 if not found
int STable::FindFreeSlot()
{
    return bm->Find();
}
