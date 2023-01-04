const userData = await fetch('https://api.github.com/users', {
        headers: {
          Authorization: `Bearer ${accessToken}`,
        },
      });
      console.log(userData.json());